#ifndef SHAPE_H_
#define SHAPE_H_

#include <graphics/Color.h>
#include <CompileConfig.h>
#include <vector>
#include <graphics/VerticeData.h>
#include <physics/Box3.h>

namespace phantom {
    class Renderer;
    class LIBEXPORT Shape {
    public:
        Shape();
        virtual ~Shape();

        static const float TEX_COORD_UNUSED;

		std::vector<Vertice> vertices;
        Vertice *verticesArray;
        std::vector<TexCoord> texCoords;
        TexCoord *texCoordsArray;

        unsigned int verticesCount;
        unsigned int vboVertices;
        unsigned int vboTexCoords;
        unsigned int textureID;

        bool isImage;
        bool isText;

        float x;
        float y;

        void setFillColor(Color color);
        void setLineColor(Color color);

        virtual void addVertex(float x, float y, float u = TEX_COORD_UNUSED, float v = TEX_COORD_UNUSED);
        void buildVBO(Renderer *renderer);

        bool hasFillColor(void);
        bool hasLineColor(void);

        const Color& getLineColor();
        const Color& getFillColor();

        const Box3& getBounds();

    private:
        Box3 _bounds;
        bool _hasFillColor;
        bool _hasLineColor;
        Color _lineColor;
        Color _fillColor;
    };
} /* namespace phantom */
#endif /* SHAPE_H_ */
