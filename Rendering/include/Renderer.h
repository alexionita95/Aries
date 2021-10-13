#ifndef RENDERER_H
#define RENDERER_H
#include <inttypes.h>
namespace aries {
	namespace rendering {
		class Renderer
		{
		public:
            void Init();
            void Render();
        private:
            float angle;
		};
	}
}

#endif
