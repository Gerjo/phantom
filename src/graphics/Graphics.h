#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <deque>
#include <string>

#include <CompileConfig.h>
#include <graphics/Color.h>
#include <graphics/shapes/Shape.h>
#include <graphics/shapes/Polygon.h>
#include <physics/Line2.h>

using namespace std;

namespace phantom {

class Composite;

class LIBEXPORT Graphics {
public:
	friend class GLRenderer;

    Graphics(phantom::Composite *parent);

    ~Graphics();

    /**
    * Call this function when you want to clear the canvas.
    *
    * @return Returns this class for chaining.
    */
    Graphics& clear();

    /**
    * Call this function when you want to begin drawing on the canvas.
    *
    * @return Returns this class for chaining.
    */
    Graphics& beginPath();

    /**
    * Call this function when you are done drawing on the canvas.
    *
    * @return Returns this class for chaining.
    */
    Graphics& fill();
    
    /**
    * Call this function when you are done drawing on the canvas.
    *
    * @return Returns this class for chaining.
    */
    Graphics& stroke();

    /**
    * Change the fill color of the graphics object.
    *
    * @return Returns this class for chaining.
    * @param color The color you want to use for the object.
    */
    Graphics& setFillStyle(Color color);
    
    /**
    * Change the line color of the graphics object.
    *
    * @return Returns this class for chaining.
    * @param color The color you want to use for the object.
    */
    Graphics& setLineStyle(Color color);

    /**
    * Draw a line.
    *
    * @return Returns this class for chaining.
    * @param startX The X start location of the line.
    * @param startY The Y start location of the line.
    * @param endX The X end location of the line.
    * @param endY The Y end location of the line.
    */
    Graphics& line(const float& startX, const float& startY, const float& endX, const float& endY);
    
    /**
    * Draw a line.
    *
    * @return Returns this class for chaining.
    * @param line Create a line using a Line2 class.
    */
    Graphics& line(const Line2& line);

    /**
    * Draw a line.
    *
    * @return Returns this class for chaining.
    * @param start Start location of the line.
    * @param end End location of the line.
    */
    Graphics& line(const Vector3& start, const Vector3& end);

    /**
    * Draw a rectangle.
    *
    * @return Returns this class for chaining.
    * @param x The X location of the rectangle relative to the component.
    * @param y The Y location of the rectangle relative to the component.
    * @param width The width of the rectangle.
    * @param height The height of the rectangle.
    * @param isFilled True if the rectangle has to be filled.
    * @param thickness If isFilled is false, you can set the linewidth here.
    */
    Graphics& rect(float x, float y, float width, float height, bool isFilled = true, float thickness = 3.0f);
    
    /**
    * Draw a rectangle.
    *
    * @return Returns this class for chaining.
    * @param box The box it should draw.
    * @param height The height of the rectangle.
    * @param isFilled True if the rectangle has to be filled.
    * @param thickness If isFilled is false, you can set the linewidth here.
    */
    Graphics& rect(const Box3& box, bool isFilled = true, float thickness = 3.0f);

    /**
    * Draw an arc.
    *
    * @return Returns this class for chaining.
    * @param x The X location relative to the component.
    * @param y The Y location relative to the component.
    * @param radius The size of the arc.
    * @param start At how much degrees this arc must begin.
    * @param end At how much degrees this arc must end.
    */
    Graphics& arc(float x, float y, float radius, float start, float end);

    /**
    * Draw an image.
    *
    * @return Returns this class for chaining.
    * @param filelocation The file location relative to the working directory.
    * @param x The X location relative to the component.
    * @param y The Y location relative to the component.
    * @param width The width of the image.
    * @param height The height of the image.
    */
    Graphics& image(const string& filelocation, float x, float y, float width, float height);
    
    /**
    * Draw some text.
    *
    * @return Returns this class for chaining.
    * @param x The X location relative to the component.
    * @param y The Y location relative to the component.
    * @param size The font size of the text.
    * @param fontlocation The location of the font relative to the working directory.
    * @param text The text you want to display.
    */
    Graphics& text(float x, float y, unsigned int size, const string& fontlocation, const string& text);

    /**
    * Rotate the graphic.
    *
    * @return Returns this class for chaining.
    * @param angle The angle you want to rotate the canvas.
    */
    Graphics& rotate(float angle);

    /**
    * Start a line drawing.
    *
    * @return Returns this class for chaining.
    * @param x The X location relative to the component where you want to start the line.
    * @param y The Y location relative to the component where you want to start the line.
    */
    Graphics& lineTo(float x, float y);
    
    /**
    * Continue a line drawing.
    *
    * @return Returns this class for chaining.
    * @param x The X location relative to the component where you want to go next with the line.
    * @param y The Y location relative to the component where you want to go next with the line.
    */
    Graphics& moveTo(float x, float y);

    /**
    * Returns the current rotation of the graphics canvas.
    *
    * @return Returns the current rotation of the graphics canvas.
    */
    float getRotation() { return _rotation; }

private:
    Graphics(Graphics& orig) : _parent(nullptr), _polygonLastX(0), _polygonLastY(0), _rotation(0), _polygonBuffer(0) {
        // Thou shalt not copy.
    }

    vector<Shape*> _finalizedShapes;
    vector<Shape*> _workspaceShapes;
    vector<Shape*> _bufferedShapes;

    Composite *_parent;
    Color _fillColor;
    Color _lineColor;

    Polygon* _polygonBuffer;

    void deleteShapes(vector<Shape*>& source);
    void moveShapes(vector<Shape*>& source, vector<Shape*>& target);
    void addShape(Shape* shape);
    void finalizePolygon();
    void initializePolygon();

    vector<Shape*>& getFinalizedShapes();
    vector<Shape*>& getBufferedShapes();

    float _rotation;

    float _polygonLastX;
    float _polygonLastY;
};

} /* namespace phantom */
#endif /* GRAPHICS_H_ */
