#ifndef AC_HTTP_IMAGE_H
#define AC_HTTP_IMAGE_H

#include "godot_cpp/classes/image.hpp"
#include "godot_cpp/classes/image_texture.hpp"
#include "godot_cpp/classes/http_request.hpp"
#include "godot_cpp/classes/texture_rect.hpp"

namespace godot{

	class ACHTTPImage: public TextureRect{
		GDCLASS(ACHTTPImage, TextureRect)

		public:
			enum Extension {
				EXTENSION_BMP,
				EXTENSION_JPG,
				EXTENSION_PNG,
				EXTENSION_TGA,
				EXTENSION_WEBP
			};

		private:
			String url = "";
			Extension extension = EXTENSION_BMP;

			HTTPRequest *_http_request;

			void _on_request_completed(int result, int response_code, PackedStringArray headers, PackedByteArray body);
			void make_request();

		protected:
			static void _bind_methods();

		public:
			void set_url(const String p_url);
			String get_url() const;
			
			void set_extension(const Extension p_extension);
			Extension get_extension() const;

			void _ready();

			ACHTTPImage();
			~ACHTTPImage();
	};
}

VARIANT_ENUM_CAST(ACHTTPImage::Extension);

#endif AC_HTTP_IMAGE_H
