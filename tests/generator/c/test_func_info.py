import unittest
from nodejs_opencv_generator.classes.func_info import FuncInfo 
from nodejs_opencv_generator.classes.class_info import ClassInfo
from nodejs_opencv_generator.classes.nodejs_wrapper_generator import NodejsWrapperGenerator
from nodejs_opencv_generator import hdr_parser

class TestFuncInfo(unittest.TestCase):
#     def test_gen_c_AKAZE_create(self):
#         classinfo = ClassInfo('cv.AKAZE', ['class cv.AKAZE', ': cv::Feature2D', [], [], None, '@brief Class implementing the AKAZE keypoint detector and descriptor extractor, described in @cite ANB13.\n\n@details AKAZE descriptors can only be used with KAZE or AKAZE keypoints. This class is thread-safe.\n\n@note When you need descriptors use Feature2D::detectAndCompute, which\nprovides better performance. When using Feature2D::detect followed by\nFeature2D::compute scale space pyramid is computed twice.\n\n@note AKAZE implements T-API. When image is passed as UMat some parts of the algorithm\nwill use OpenCL.\n\n@note [ANB13] Fast Explicit Diffusion for Accelerated Features in Nonlinear\nScale Spaces. Pablo F. Alcantarilla, Jesús Nuevo and Adrien Bartoli. In\nBritish Machine Vision Conference (BMVC), Bristol, UK, September 2013.'])
#         funcinfo = FuncInfo('AKAZE', 'create', 'cv::AKAZE::create', False, 'cv', True)

#         funcinfo.add_variant(['cv.AKAZE.create', 'Ptr_AKAZE', ['/S'], [['AKAZE_DescriptorType', 'descriptor_type', 'AKAZE::DESCRIPTOR_MLDB', []], ['int', 'descriptor_size', '0', []], ['int', 'descriptor_channels', '3', []], ['float', 'threshold', '0.001f', []], ['int', 'nOctaves', '4', []], ['int', 'nOctaveLayers', '4', []], ['KAZE_DiffusivityType', 'diffusivity', 'KAZE::DIFF_PM_G2', []]], 'Ptr<AKAZE>', '@brief The AKAZE constructor\n\n    @param descriptor_type Type of the extracted descriptor: DESCRIPTOR_KAZE,\n    DESCRIPTOR_KAZE_UPRIGHT, DESCRIPTOR_MLDB or DESCRIPTOR_MLDB_UPRIGHT.\n    @param descriptor_size Size of the descriptor in bits. 0 -\\> Full size\n    @param descriptor_channels Number of channels in the descriptor (1, 2, 3)\n    @param threshold Detector response threshold to accept point\n    @param nOctaves Maximum octave evolution of the image\n    @param nOctaveLayers Default number of sublevels per scale level\n    @param diffusivity Diffusivity type. DIFF_PM_G1, DIFF_PM_G2, DIFF_WEICKERT or\n    DIFF_CHARBONNIER'], dict(AKAZE= classinfo))

#         codegen = NodejsWrapperGenerator()
#         codegen.parser = hdr_parser.CppHeaderParser(generate_umat_decls=True, generate_gpumat_decls=True)
#         codegen.classes=dict(AKAZE= classinfo)
#         expected_output = """Napi::Value AKAZEWrapper::CreateStatic(const Napi::CallbackInfo &info) {
#     Napi::FunctionReference *constructor = info.Env().GetInstanceData<Napi::FunctionReference>();
#     return constructor->New(CallbackInfoToVector(info));
# }"""
        
#         generated = funcinfo.gen_c(codegen)
#         self.assertEqual(generated, expected_output)
    def test_gen_ts_AKAZE_set_descriptor_type(self):
        classinfo = ClassInfo('cv.AKAZE', ['class cv.AKAZE', ': cv::Feature2D', [], [], None, '@brief Class implementing the AKAZE keypoint detector and descriptor extractor, described in @cite ANB13.\n\n@details AKAZE descriptors can only be used with KAZE or AKAZE keypoints. This class is thread-safe.\n\n@note When you need descriptors use Feature2D::detectAndCompute, which\nprovides better performance. When using Feature2D::detect followed by\nFeature2D::compute scale space pyramid is computed twice.\n\n@note AKAZE implements T-API. When image is passed as UMat some parts of the algorithm\nwill use OpenCL.\n\n@note [ANB13] Fast Explicit Diffusion for Accelerated Features in Nonlinear\nScale Spaces. Pablo F. Alcantarilla, Jesús Nuevo and Adrien Bartoli. In\nBritish Machine Vision Conference (BMVC), Bristol, UK, September 2013.'])
        funcinfo = FuncInfo('AKAZE', 'setDescriptorType', 'cv::AKAZE::setDescriptorType', False, 'cv', False)

        funcinfo.add_variant(['cv.AKAZE.setDescriptorType', 'void', ['/V', '/PV'], [['AKAZE_DescriptorType', 'dtype', '', []]], 'void', ''], dict(AKAZE= classinfo))


        expected_output = """Napi::Value AKAZEWrapper::setDescriptorType(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->cvdata;
    Napi::Value *jsobj_dtype = NULL;
    AKAZE_DescriptorType dtype = static_cast<AKAZE_DescriptorType>(0);

    const char *keywords[] = { "dtype", NULL };
    if (JsArg_ParseTupleAndKeywords(info, "O:AKAZE.setDescriptorType", (char**)keywords, &jsobj_dtype) &&
        jsopencv_to_safe(jsobj_dtype, dtype, ArgInfo("dtype", 0)))
    {
        ERRWRAP2_NAPI(env, _self_->setDescriptorType(dtype));
        return env.Null();
    }

    return env.Null();
}

"""

        codegen = NodejsWrapperGenerator()
        codegen.parser = hdr_parser.CppHeaderParser(generate_umat_decls=True, generate_gpumat_decls=True)
        codegen.classes=dict(AKAZE= classinfo)
        self.assertEqual(funcinfo.gen_cpp(codegen), expected_output)


    def test_gen_ts_AKAZE_get_descriptor_size(self):
        class_info = ClassInfo('cv.AKAZE', ['class cv.AKAZE', ': cv::Feature2D', [], [], None, '@brief Class implementing the AKAZE keypoint detector and descriptor extractor, described in @cite ANB13.\n\n@details AKAZE descriptors can only be used with KAZE or AKAZE keypoints. This class is thread-safe.\n\n@note When you need descriptors use Feature2D::detectAndCompute, which\nprovides better performance. When using Feature2D::detect followed by\nFeature2D::compute scale space pyramid is computed twice.\n\n@note AKAZE implements T-API. When image is passed as UMat some parts of the algorithm\nwill use OpenCL.\n\n@note [ANB13] Fast Explicit Diffusion for Accelerated Features in Nonlinear\nScale Spaces. Pablo F. Alcantarilla, Jesús Nuevo and Adrien Bartoli. In\nBritish Machine Vision Conference (BMVC), Bristol, UK, September 2013.'])
        known_classes=dict(AKAZE= class_info)
        funcinfogetDescriptorSize = FuncInfo("AKAZE","getDescriptorSize","getDescriptorSize",False,"cv",False)
        decl =  ['cv.AKAZE.getDescriptorSize', 'int', ['/C', '/V', '/PV'], [], 'int', '']
        funcinfogetDescriptorSize.add_variant(decl,known_classes,False)
        class_info.methods.setdefault('getDescriptorSize', funcinfogetDescriptorSize)

        expected_output = """Napi::Value AKAZEWrapper::getDescriptorSize(const Napi::CallbackInfo &info) {
    Napi::Env env = info.Env();
    Ptr<cv::AKAZE> _self_ = this->cvdata;
    int retval;

    if (info.Length() == 0 || (info.Length() == 1 && info[0].IsObject() && info[0].IsEmpty()))
    {
        ERRWRAP2_NAPI(env, retval = _self_->getDescriptorSize());
        return jsopencv_from(env, retval);
    }

    return env.Null();
}

"""

        codegen = NodejsWrapperGenerator()
        codegen.parser = hdr_parser.CppHeaderParser(generate_umat_decls=True, generate_gpumat_decls=True)
        codegen.classes=dict(AKAZE= class_info)
        self.assertEqual(funcinfogetDescriptorSize.gen_cpp(codegen), expected_output)