#ifndef AC_HTTP_IMAGE_H
#define AC_HTTP_IMAGE_H

#include <godot_cpp/classes/texture_rect.hpp>
#include <godot_cpp/classes/http_request.hpp>
#include <godot_cpp/classes/image.hpp>
#include <godot_cpp/classes/image_texture.hpp>

namespace godot{

    class ACHTTPImage: public TextureRect{
        GDCLASS(ACHTTPImage, TextureRect)

        public:
            ACHTTPImage();
            ~ACHTTPImage();
            String url = "";
            String get_url() const;
            void set_url(const String url);
            int extension = EXTENSION_BMP;
            int get_extension() const;
            void set_extension(const int extension);
            enum Extension {EXTENSION_BMP, EXTENSION_JPG, EXTENSION_PNG, EXTENSION_TGA, EXTENSION_WEBP};
        private:
            HTTPRequest* http_request;
            void _on_request_completed(int result, int response_code, PackedStringArray headers, PackedByteArray body);
            void _make_request();
        protected:
            static void _bind_methods();

    };
}

VARIANT_ENUM_CAST(ACHTTPImage::Extension);

#endif
