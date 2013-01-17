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

        bool isImage;
        bool isText;

        float x;
        float y;

        /**
        * Set the fill color of the shape.
        *
        * @param color The color you want to use for the shape.
        */
        void setFillColor(Color color);
        
        /**
        * Set the line color of the shape.
        *
        * @param color The color you want to use for the shape.
        */
        void setLineColor(Color color);

        /**
        * Add a vertex to the shape. The renderer will iterate through all the vertices to draw them.
        *
        * @param x The x location of the vertex
        * @param y The y location of the vertex
        * @param u The u texture coordinate associated with the vertex
        * @param v The v texture coordinate associated with the vertex
        */
        virtual void addVertex(float x, float y, float u = TEX_COORD_UNUSED, float v = TEX_COORD_UNUSED);

        /**
        * When the shape gets added to the Graphics class the graphics class calls this function. This function then calls the renderer to build VBO's for example.
        * 
        * @param renderer The renderer class.
        */
        void buildShape(Renderer *renderer);
        
        /**
        * When the shape gets removed from the Graphics class the graphics class calls this function. This function then calls the renderer to destroy VBO's for example.
        * 
        * @param renderer The renderer class.
        */
        void destroyShape(Renderer *renderer);

        /**
        * Returns true if the shape has a fill color.
        *
        * @return Returns true if the shape has a fill color.
        */
        bool hasFillColor(void);

        /**
        * Returns true if the shape has a line color.
        *
        * @return Returns true if the shape has a fill color.
        */
        bool hasLineColor(void);

        /**
        * Returns the line color of the shape.
        *
        * @return Returns the line color of the shape.
        */
        const Color& getLineColor();
        
        /**
        * Returns the line color of the shape.
        *
        * @return Returns the line color of the shape.
        */
        const Color& getFillColor();

        /**
        * Returns the size of the shape.
        *
        * @return Returns the size of the shape.
        */
        const Box3& getBounds();

        /**
        * Returns the total shapes that exist in the game.
        *
        * @return Returns the total shapes that exist in the game.
        */
        static unsigned getShapecount();

    protected:
        Box3 _bounds;
    private:
        static unsigned shapecount;

        bool _hasFillColor;
        bool _hasLineColor;
        Color _lineColor;
        Color _fillColor;
    };
} /* namespace phantom */
#endif /* SHAPE_H_ */
