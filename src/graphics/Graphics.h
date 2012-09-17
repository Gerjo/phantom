/*
 * Graphics.h
 *
 *  Created on: Aug 23, 2012
 *      Author: koen
 */

#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <Eigen/Geometry>

#include <core/PhantomGame.h>
#include <core/Composite.h>

namespace phantom {

class Graphics: public Composite
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW;
    float lineWidth;
    Eigen::Vector4f strokeColor;
    Eigen::Vector4f fillColor;

    virtual ~Graphics() {};

    void onAdd(Composite *parent);

    virtual void setup(PhantomGame *game) = 0;

    virtual void save() = 0;
    virtual void restore() = 0;

    virtual void fill() = 0;
    virtual void stroke() = 0;

    virtual void moveTo(float x, float y) = 0;
    virtual void lineTo(float x, float y) = 0;

};

} /* namespace phantom */
#endif /* GRAPHICS_H_ */
