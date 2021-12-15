#include "framework.h"
#include "ShootingGame.h"

Text::Text(string name, float px, float py, wstring text, unsigned char r, unsigned char g, unsigned char b, int size) 
    : GameObject("", name ,true, px, py)
{
    this->r = r;
    this->g = g;
    this->b = b;

    this->text = text;
    this->size = size;
}

Text::~Text()
{
    FT_Done_Face(face);
    FT_Done_FreeType(library);
}

void Text::start()
{
    if (FT_Init_FreeType(&library) != 0)
    {
        cout << "폰트 라이브러리 초기화 실패" << endl;
    }

    if (FT_New_Face(library, "Asset/Font/Bold.ttf", 0, &face) != 0)
    {
        cout << "폰트 파일 로드하기 실패 " << endl;
    }

    FT_Set_Pixel_Sizes(face, size, size);
}

void Text::draw()
{
    //폰트 출력 좌표(출력하면서..변경)
    int fontx = getPx();
    int fonty = getPy();

    for (int i = 0; i < text.length(); i++)
    {
        int index = FT_Get_Char_Index(face, text[i]);
        FT_Load_Glyph(face, index, FT_LOAD_DEFAULT);         //로드한 그립은 face->glyph에 저장됨
        FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL); //로드한 크립을 화면에 출력가능한 이미지 픽셀 형태로..변경하기

        //이미지 변환 저장
        int width = face->glyph->bitmap.width;  //변환이미지의 가로 크기
        int height = face->glyph->bitmap.rows;   //변환이미지의 세로 크기
        unsigned char* buffer = face->glyph->bitmap.buffer;  //변환이미지의 데이타

        //폰트 출력 위치 재조정
        int left = face->glyph->bitmap_left;
        int top  = face->glyph->bitmap_top;

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                unsigned char value = buffer[y * width + x];

                if (value != 0)
                {
                    //배경색 가져오기
                    unsigned char br, bg, bb;
                    getPixel(fontx + x + left, fonty + y - top, br, bg, bb);

                    //폰트색 r,g,b 로 배경색과 알파 블렌딩하기, value가 알파값(투명도값)으로 사용됨
                    unsigned char R = (value * r + (255 - value) * br) / 255;
                    unsigned char G = (value * g + (255 - value) * bg) / 255;
                    unsigned char B = (value * b + (255 - value) * bb) / 255;

                    setPixel(fontx + x + left, fonty + y - top, R, G, B);
                }              
            }            
        }

        fontx += face->glyph->advance.x / 64;
        fonty -= face->glyph->advance.y / 64;
    }
}

void Text::setText(wstring text)
{
    this->text = text;
}