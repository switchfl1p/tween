# tween
a C++ library for time-based interpolation between keyframes.

This is a fork of part of the framework used in [gltut by Jason L. McKesson](https://github.com/paroj/gltut)

## The changes:
- switched from freeglut to glfw
- fixed the forward declaration of functions in global scope in Interpolators.h 

## How it works

### Timer

Provides 3 types of timers (single, loop and infinite) and a set of functions to operate them such as pause, fast forward and rewind.
Most importantly it provides a getAlpha() method which returns a [0, 1] value representing progress through the timer's duration, for use with the interpolators.

### Interpolators

#### Timed Linear Interpolator:

Loads a set of (value, time) pairs into the interpolator.
Times must be in [0, 1] and in ascending order.
If looping, the first value is appended at the end to allow smooth wraparound. 

#### Linear Interpolator:

Loads a set of values and automatically distributes them evenly across [0, 1].
Unlike TimedLinearInterpolator, no timestamps are required in the input.
If looping, the last value is duplicated at the end to pad the cycle boundary.

#### Constant Velocity Linear Interpolator:

Interpolates with a constant velocity between positions.
This interpolator maps a range of [0, 1) onto a set of values. However, it takes the distance between these values. There must be a free function called "distance" which takes two ValueType's and returns a float distance between them.
The idea is that, if you add 0.1 to your alpha value, you will always get a movement of the same distance.
Not necessarily between the initial and final points, but the object will have moved at the same speed along the path.

## Usage

To use TimedLinearInterpolator with your type T, you must provide:
- YourValueType getValue(const T &data);
- float getTime(const T &data);

To use ConstVelLinearInterpolator with your type T, you must provide:
- float distance(const YourValueType &a, const YourValueType &b); 

See main.cpp for example usage