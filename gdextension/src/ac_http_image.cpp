#include "ac_http_image.h"

#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/variant/utility_functions.hpp"

using namespace godot;

void ACHTTPImage::set_url(const String p_url){
	url = p_url;
}

String ACHTTPImage::get_url() const {
	return url;
}

void ACHTTPImage::set_extension(const ACHTTPImage::Extension p_extension){
	extension = p_extension;
}

ACHTTPImage::Extension ACHTTPImage::get_extension() const {
	return extension;
}

void ACHTTPImage::_on_request_completed(int result, int response_code, PackedStringArray headers, PackedByteArray body){
	Image *image = memnew(Image);
	if(extension == EXTENSION_BMP){
		image->load_bmp_from_buffer(body);
	}
	else if(extension == EXTENSION_JPG){
		image->load_jpg_from_buffer(body);
	}
	else if(extension == EXTENSION_PNG){
		image->load_png_from_buffer(body);
	}
	else if(extension == EXTENSION_TGA){
		image->load_tga_from_buffer(body);
	}
	else if(extension == EXTENSION_WEBP){
		image->load_webp_from_buffer(body);
	}
	ImageTexture *image_texture = memnew(ImageTexture);
	set_texture(image_texture->create_from_image(image));
	emit_signal("request_finished");
}

void ACHTTPImage::_ready(){
	if(!Engine::get_singleton()->is_editor_hint()){
		make_request();
	}
}

void ACHTTPImage::make_request(){
	_http_request->request(url);
}

void ACHTTPImage::_bind_methods(){
	ClassDB::bind_method(D_METHOD("set_url", "url"), &ACHTTPImage::set_url);
	ClassDB::bind_method(D_METHOD("get_url"), &ACHTTPImage::get_url);
	ClassDB::bind_method(D_METHOD("set_extension", "extension"), &ACHTTPImage::set_extension);
	ClassDB::bind_method(D_METHOD("get_extension"), &ACHTTPImage::get_extension);

	ClassDB::bind_method(D_METHOD("make_request"), &ACHTTPImage::make_request);
	ClassDB::bind_method(D_METHOD("_on_request_completed"), &ACHTTPImage::_on_request_completed);

	ADD_PROPERTY(PropertyInfo(Variant::STRING, "url"), "set_url", "get_url");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "extension", PROPERTY_HINT_ENUM, "bmp,jpg,png,tga,webp"), "set_extension", "get_extension");

	BIND_ENUM_CONSTANT(EXTENSION_BMP);
	BIND_ENUM_CONSTANT(EXTENSION_JPG);
	BIND_ENUM_CONSTANT(EXTENSION_PNG);
	BIND_ENUM_CONSTANT(EXTENSION_TGA);
	BIND_ENUM_CONSTANT(EXTENSION_WEBP);

	ADD_SIGNAL(MethodInfo("request_finished"));
}

ACHTTPImage::ACHTTPImage(){
	_http_request = memnew(HTTPRequest);
	add_child(_http_request, false, INTERNAL_MODE_FRONT);
	_http_request->connect("request_completed", Callable(this, "_on_request_completed"));
}

ACHTTPImage::~ACHTTPImage(){}
