#include "ImageDisplay.h"
int main(int argc, char* argv[])
{
	ImageWindow window;
	if (window.Init())
	{
		if (window.LoadMedia())
		{
			while (!window.ShouldQuit())
			{
				while (SDL_PollEvent(window.GetSDLEvent()) != 0)
				{
					if (window.GetSDLEvent()->type == SDL_QUIT)
					{
						window.SetQuitFlag();
					}
				}

				SDL_BlitSurface(window.GetImageSurface(), NULL, window.GetScreenSurface(), NULL);
				window.UpdateWindowSurface();
				SDL_Delay(100);
			}
		}
	}
	window.Close();

	return 0;
}