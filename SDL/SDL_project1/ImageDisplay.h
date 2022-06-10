#pragma once
#include <SDL.h>
#include <stdio.h>
#include <string>

const std::string gImagePath = "C:\\Users\\souvi\\Pictures\\face.bmp";
const std::string gWindowName = "Image Display";
constexpr int gWidth = 720;
constexpr int gHeight = 480;

class ImageWindow
{
private:
	int m_Width{ 0 };
	int m_Height{ 0 };
	SDL_Window* m_window{ nullptr };
	SDL_Surface* m_screenSurface{ nullptr };
	SDL_Surface* m_imageSurface{ nullptr };
	std::string m_windowName = gWindowName;
	bool m_quitFlag{ false };
	SDL_Event m_event;
public:
	ImageWindow();
	ImageWindow(const std::string&);
	~ImageWindow();

	inline std::string GetWindowName() const
	{
		return m_windowName;
	}
	inline int GetWidth() const
	{
		return m_Width;
	}
	inline int GetHeight() const
	{
		return m_Height;
	}
	inline SDL_Window* GetWindow() const
	{
		return m_window;
	}
	inline SDL_Surface* GetScreenSurface() const
	{
		return m_screenSurface;
	}
	inline SDL_Surface* GetImageSurface() const
	{
		return m_imageSurface;
	}
	inline void SetWindow(SDL_Window* window)
	{
		m_window = window;
	}
	inline void SetScreenSurface(SDL_Surface* surface)
	{
		m_screenSurface = surface;
	}
	inline void SetImageSurface(SDL_Surface* imageSurface)
	{
		m_imageSurface = imageSurface;
	}
	inline bool ShouldQuit() const
	{
		return m_quitFlag;
	}
	inline void SetQuitFlag()
	{
		m_quitFlag = true;
	}
	inline void ClearQuitFlag()
	{
		m_quitFlag = false;
	}
	inline SDL_Event* GetSDLEvent()
	{
		return &m_event;
	}
	bool Init();
	void Close();
	bool LoadMedia();
	void UpdateWindowSurface();
};