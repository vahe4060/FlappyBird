#pragma once
class LoaderParams
{
private:
    int xpos, ypos;
    int Width, Height;
    const char* ID;
public:
    LoaderParams(int x, int y, int w, int h, const char* id) :
        xpos(x),
        ypos(y),
        Width(w),
        Height(h),
        ID(id)
    {}

    int getX() const { return xpos; }
    int getY() const { return ypos; }
    int width() const { return Width; }
    int heigt() const { return Height; }
    const char* id() const { return ID; }
};