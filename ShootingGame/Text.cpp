#include "framework.h"
#include "ShootingGame.h"

Text::Text(float px, float py, wstring text, unsigned char r, unsigned char g, unsigned char b, int size) : GameObject("","",true, px, py)
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
        cout << "��Ʈ ���̺귯�� �ʱ�ȭ ����" << endl;
    }

    if (FT_New_Face(library, "Asset/Font/Bold.ttf", 0, &face) != 0)
    {
        cout << "��Ʈ ���� �ε��ϱ� ���� " << endl;
    }

    FT_Set_Pixel_Sizes(face, size, size);
}

void Text::draw()
{
    //��Ʈ ��� ��ǥ(����ϸ鼭..����)
    int fontx = getPx();
    int fonty = getPy();

    for (int i = 0; i < text.length(); i++)
    {
        int index = FT_Get_Char_Index(face, text[i]);
        FT_Load_Glyph(face, index, FT_LOAD_DEFAULT);         //�ε��� �׸��� face->glyph�� �����
        FT_Render_Glyph(face->glyph, FT_RENDER_MODE_NORMAL); //�ε��� ũ���� ȭ�鿡 ��°����� �̹��� �ȼ� ���·�..�����ϱ�

        //�̹��� ��ȯ ����
        int width = face->glyph->bitmap.width;  //��ȯ�̹����� ���� ũ��
        int height = face->glyph->bitmap.rows;   //��ȯ�̹����� ���� ũ��
        unsigned char* buffer = face->glyph->bitmap.buffer;  //��ȯ�̹����� ����Ÿ

        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                unsigned char value = buffer[y * width + x];

                if (value != 0)
                {
                    setPixel(fontx + x, fonty + y, r, g, b);
                }              
            }            
        }

        fontx += face->glyph->advance.x / 64;
        fonty += face->glyph->advance.y / 64;
    }
}