#ifndef APP_H
#define APP_H

#include<glad/glad.h>

#include<memory>
#include <export.h>
namespace aries {
	namespace rendering {
		class App
		{
		public:
			EXPORTED App();
			EXPORTED ~App();
			virtual void EXPORTED OnRenderFrame() = 0;
			void EXPORTED Run();

		private:
			void Init();


		};
	}
}
#endif // !APP_H
