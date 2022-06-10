#include "ImageDisplay.h"

ImageWindow::ImageWindow()
{
	m_Width = gWidth;
	m_Height = gHeight;
	ClearQuitFlag();
}

ImageWindow::ImageWindow(const std::string& windowName):ImageWindow()
{
	m_windowName = windowName;
}

ImageWindow::~ImageWindow()
{

}

bool ImageWindow::Init()
{
	bool retVal = false;

	if (SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		printf("SDL_Init failed with error %s\n", SDL_GetError());
	}
	else
	{
		SDL_Window* window = SDL_CreateWindow(GetWindowName().c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, GetWidth(), GetHeight(), SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window : %s\n", SDL_GetError());
		}
		else
		{
			SetWindow(window);
			SDL_Surface* windowSurface = SDL_GetWindowSurface(window);
			if (windowSurface == NULL)
			{
				printf("Failed to get windowSurface: %s\n", SDL_GetError());
			}
			else
			{
				SetScreenSurface(windowSurface);
				retVal = true;
			}
		}
	}
	return retVal;
}

void ImageWindow::Close()
{
	SDL_FreeSurface(GetImageSurface());
	SetImageSurface(nullptr);

	SDL_DestroyWindow(GetWindow());
	SetWindow(nullptr);

	SDL_Quit();
}

bool ImageWindow::LoadMedia()
{
	bool retVal = false;
	SDL_Surface* imageSurface = SDL_LoadBMP(gImagePath.c_str());
	if (imageSurface == NULL)
	{
		printf("Failed to load imageSurface : %s\n", SDL_GetError());
	}
	else
	{
		SetImageSurface(imageSurface);
		retVal = true;
	}
	return retVal;
}

void ImageWindow::UpdateWindowSurface()
{
	SDL_UpdateWindowSurface(GetWindow());
}
