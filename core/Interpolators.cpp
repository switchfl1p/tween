#pragma once

#include <vector>

template<typename ValueType>
class WeightedLinearInterpolator
{
public:
    size_t numSegments() const {
        return values.empty() ? 0 : values.size() - 1;
    }

    ValueType interpolate(float alpha) const {
        if (values.empty())
            return ValueType();
        if (values.size() == 1)
            return values[0].data;

        //Find which segment we are within
        size_t segment = 1;
        for (; segment < values.size(); segment++) {
            if (alpha < values[segment].weight)
                break;
        }
        
        //if alpha >= than 1
        if (segment == values.size())
            return values.back().data;

        float section_alpha = alpha - values[segment - 1].weight; //how far into the specific segment
        section_alpha /= values[segment].weight - values[segment - 1].weight; //normalize it to [0,1]

        float inv_sec_alpha = 1.0f - section_alpha;

        return values[segment - 1].data * inv_sec_alpha + values[segment].data * section_alpha;
    }

protected:
    WeightedLinearInterpolator() {}

    struct Data {
        ValueType data;
        float weight;
    };

    std::vector<Data> values;
};

template<typename ValueType>
class TimedLinearInterpolator : public WeightedLinearInterpolator<ValueType> {
public:

    template<typename BidirectionalRange>
    void setValues(const BidirectionalRange &data, bool is_looping = true) {

    }
};