#ifndef CV2_NUMPY_H2
#define CV2_NUMPY_H2

#include "opencv2/core.hpp"
#include "comm.h"
#include "js_as_py.h"

struct JsSafeSeqItem
{
    Napi::Value * item;
    JsSafeSeqItem(const Napi::Value *obj, size_t idx) { item = JsSequence_GetItem(obj, idx); }
    ~JsSafeSeqItem() { /* Js_XDECREF(item);*/ }

private:
    JsSafeSeqItem(const JsSafeSeqItem&); // = delete
    JsSafeSeqItem& operator=(const JsSafeSeqItem&); // = delete
};

template <class T>
class RefWrapper
{
public:
    RefWrapper(T& item) : item_(item) {}

    T& get() CV_NOEXCEPT { return item_; }

private:
    T& item_;
};

// In order to support this conversion on 3.x branch - use custom reference_wrapper
// and C-style array instead of std::array<T, N>
template <class T, std::size_t N>
bool JsParseSequence(const Napi::Value* obj, RefWrapper<T> (&value)[N], const ArgInfo& info)
{
    if (!obj || obj->IsNull() || obj->IsUndefined())
    {
        return true;
    }
    {
        return true;
    }
    if (!JsSequence_Check(obj))
    {
        failmsg(obj->Env(), "Can't parse '%s'. Input argument doesn't provide sequence "
                "protocol", info.name);
        return false;
    }
    const std::size_t sequenceSize = JsSequence_Size(obj);
    if (sequenceSize != N)
    {
        failmsg(obj->Env(), "Can't parse '%s'. Expected sequence length %lu, got %lu",
                info.name, N, sequenceSize);
        return false;
    }
    for (std::size_t i = 0; i < N; ++i)
    {
        JsSafeSeqItem seqItem(obj, i);
        if (!jsopencv_to(seqItem.item, value[i].get(), info))
        {
            failmsg(obj->Env(), "Can't parse '%s'. Sequence item with index %lu has a "
                    "wrong type", info.name, i);
            return false;
        }
    }
    return true;
}


#endif