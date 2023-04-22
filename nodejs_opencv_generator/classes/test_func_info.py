import unittest
from .func_info import FuncInfo 
from .class_info import ClassInfo
from .nodejs_wrapper_generator import NodejsWrapperGenerator
from .. import hdr_parser

class TestFuncInfo(unittest.TestCase):

    def test_gen_ts_typings_AKAZE_create(self):
        classinfo = ClassInfo('cv.AKAZE', ['class cv.AKAZE', ': cv::Feature2D', [], [], None, '@brief Class implementing the AKAZE keypoint detector and descriptor extractor, described in @cite ANB13.\n\n@details AKAZE descriptors can only be used with KAZE or AKAZE keypoints. This class is thread-safe.\n\n@note When you need descriptors use Feature2D::detectAndCompute, which\nprovides better performance. When using Feature2D::detect followed by\nFeature2D::compute scale space pyramid is computed twice.\n\n@note AKAZE implements T-API. When image is passed as UMat some parts of the algorithm\nwill use OpenCL.\n\n@note [ANB13] Fast Explicit Diffusion for Accelerated Features in Nonlinear\nScale Spaces. Pablo F. Alcantarilla, Jesús Nuevo and Adrien Bartoli. In\nBritish Machine Vision Conference (BMVC), Bristol, UK, September 2013.'])
        funcinfo = FuncInfo('AKAZE', 'create', 'cv::AKAZE::create', False, 'cv', True)

        funcinfo.add_variant(['cv.AKAZE.create', 'Ptr_AKAZE', ['/S'], [['AKAZE_DescriptorType', 'descriptor_type', 'AKAZE::DESCRIPTOR_MLDB', []], ['int', 'descriptor_size', '0', []], ['int', 'descriptor_channels', '3', []], ['float', 'threshold', '0.001f', []], ['int', 'nOctaves', '4', []], ['int', 'nOctaveLayers', '4', []], ['KAZE_DiffusivityType', 'diffusivity', 'KAZE::DIFF_PM_G2', []]], 'Ptr<AKAZE>', '@brief The AKAZE constructor\n\n    @param descriptor_type Type of the extracted descriptor: DESCRIPTOR_KAZE,\n    DESCRIPTOR_KAZE_UPRIGHT, DESCRIPTOR_MLDB or DESCRIPTOR_MLDB_UPRIGHT.\n    @param descriptor_size Size of the descriptor in bits. 0 -\\> Full size\n    @param descriptor_channels Number of channels in the descriptor (1, 2, 3)\n    @param threshold Detector response threshold to accept point\n    @param nOctaves Maximum octave evolution of the image\n    @param nOctaveLayers Default number of sublevels per scale level\n    @param diffusivity Diffusivity type. DIFF_PM_G1, DIFF_PM_G2, DIFF_WEICKERT or\n    DIFF_CHARBONNIER'], dict(AKAZE= classinfo))

        expected_output = ["static create(opts?: {descriptor_type?: number, descriptor_size?: number, descriptor_channels?: number, threshold?: number, nOctaves?: number, nOctaveLayers?: number, diffusivity?: number}): AKAZE;"]
        codegen = NodejsWrapperGenerator()
        codegen.parser = hdr_parser.CppHeaderParser(generate_umat_decls=True, generate_gpumat_decls=True)
        codegen.classes=dict(AKAZE= classinfo)
        codegen.add_enum('cv.AKAZE.DescriptorType',['enum cv.AKAZE.DescriptorType', '', [], [['const cv.AKAZE.DESCRIPTOR_KAZE_UPRIGHT', '2', [], [], None, ''], ['const cv.AKAZE.DESCRIPTOR_KAZE', '3', [], [], None, ''], ['const cv.AKAZE.DESCRIPTOR_MLDB_UPRIGHT', '4', [], [], None, ''], ['const cv.AKAZE.DESCRIPTOR_MLDB', '5', [], [], None, '']], None, ''])
        codegen.add_enum('cv.KAZE.DiffusivityType', ['enum cv.KAZE.DiffusivityType', '', [], [['const cv.KAZE.DIFF_PM_G1', '0', [], [], None, ''], ['const cv.KAZE.DIFF_PM_G2', '1', [], [], None, ''], ['const cv.KAZE.DIFF_WEICKERT', '2', [], [], None, ''], ['const cv.KAZE.DIFF_CHARBONNIER', '3', [], [], None, '']], None, ''])
        self.assertEqual(funcinfo.gen_ts_typings(codegen), expected_output)
                
    def test_gen_ts_typings_AKAZE_set_descriptor_type(self):
        classinfo = ClassInfo('cv.AKAZE', ['class cv.AKAZE', ': cv::Feature2D', [], [], None, '@brief Class implementing the AKAZE keypoint detector and descriptor extractor, described in @cite ANB13.\n\n@details AKAZE descriptors can only be used with KAZE or AKAZE keypoints. This class is thread-safe.\n\n@note When you need descriptors use Feature2D::detectAndCompute, which\nprovides better performance. When using Feature2D::detect followed by\nFeature2D::compute scale space pyramid is computed twice.\n\n@note AKAZE implements T-API. When image is passed as UMat some parts of the algorithm\nwill use OpenCL.\n\n@note [ANB13] Fast Explicit Diffusion for Accelerated Features in Nonlinear\nScale Spaces. Pablo F. Alcantarilla, Jesús Nuevo and Adrien Bartoli. In\nBritish Machine Vision Conference (BMVC), Bristol, UK, September 2013.'])
        funcinfo = FuncInfo('AKAZE', 'setDescriptorType', 'cv::AKAZE::setDescriptorType', False, 'cv', False)

        funcinfo.add_variant(['cv.AKAZE.setDescriptorType', 'void', ['/V', '/PV'], [['AKAZE_DescriptorType', 'dtype', '', []]], 'void', ''], dict(AKAZE= classinfo))

        expected_output = ["setDescriptorType(dtype: number): null;"]
        codegen = NodejsWrapperGenerator()
        codegen.parser = hdr_parser.CppHeaderParser(generate_umat_decls=True, generate_gpumat_decls=True)
        codegen.classes=dict(AKAZE= classinfo)
        codegen.add_enum('cv.AKAZE.DescriptorType',['enum cv.AKAZE.DescriptorType', '', [], [['const cv.AKAZE.DESCRIPTOR_KAZE_UPRIGHT', '2', [], [], None, ''], ['const cv.AKAZE.DESCRIPTOR_KAZE', '3', [], [], None, ''], ['const cv.AKAZE.DESCRIPTOR_MLDB_UPRIGHT', '4', [], [], None, ''], ['const cv.AKAZE.DESCRIPTOR_MLDB', '5', [], [], None, '']], None, ''])
        self.assertEqual(funcinfo.gen_ts_typings(codegen), expected_output)
        
    def test_gen_ts_typings_AKAZE_set_n_octave_layers(self):
        classinfo = ClassInfo('cv.AKAZE', ['class cv.AKAZE', ': cv::Feature2D', [], [], None, '@brief Class implementing the AKAZE keypoint detector and descriptor extractor, described in @cite ANB13.\n\n@details AKAZE descriptors can only be used with KAZE or AKAZE keypoints. This class is thread-safe.\n\n@note When you need descriptors use Feature2D::detectAndCompute, which\nprovides better performance. When using Feature2D::detect followed by\nFeature2D::compute scale space pyramid is computed twice.\n\n@note AKAZE implements T-API. When image is passed as UMat some parts of the algorithm\nwill use OpenCL.\n\n@note [ANB13] Fast Explicit Diffusion for Accelerated Features in Nonlinear\nScale Spaces. Pablo F. Alcantarilla, Jesús Nuevo and Adrien Bartoli. In\nBritish Machine Vision Conference (BMVC), Bristol, UK, September 2013.'])
        funcinfo = FuncInfo('AKAZE', 'setNOctaveLayers', 'cv::AKAZE::setNOctaveLayers', False, 'cv', False)

        funcinfo.add_variant(['cv.AKAZE.setNOctaveLayers', 'void', ['/V', '/PV'], [['int', 'octaveLayers', '', []]], 'void', ''], dict(AKAZE= classinfo))

        expected_output = ["setNOctaveLayers(octaveLayers: number): null;"]
        codegen = NodejsWrapperGenerator()
        codegen.parser = hdr_parser.CppHeaderParser(generate_umat_decls=True, generate_gpumat_decls=True)
        codegen.classes=dict(AKAZE= classinfo)
        self.assertEqual(funcinfo.gen_ts_typings(codegen), expected_output)
    
    def test_gen_ts_typings_AKAZE_get_diffusivity(self):
        classinfo = ClassInfo('cv.AKAZE', ['class cv.AKAZE', ': cv::Feature2D', [], [], None, '@brief Class implementing the AKAZE keypoint detector and descriptor extractor, described in @cite ANB13.\n\n@details AKAZE descriptors can only be used with KAZE or AKAZE keypoints. This class is thread-safe.\n\n@note When you need descriptors use Feature2D::detectAndCompute, which\nprovides better performance. When using Feature2D::detect followed by\nFeature2D::compute scale space pyramid is computed twice.\n\n@note AKAZE implements T-API. When image is passed as UMat some parts of the algorithm\nwill use OpenCL.\n\n@note [ANB13] Fast Explicit Diffusion for Accelerated Features in Nonlinear\nScale Spaces. Pablo F. Alcantarilla, Jesús Nuevo and Adrien Bartoli. In\nBritish Machine Vision Conference (BMVC), Bristol, UK, September 2013.'])
        funcinfo = FuncInfo('AKAZE', 'getDiffusivity', 'cv::AKAZE::getDiffusivity', False, 'cv', False)

        funcinfo.add_variant(['cv.AKAZE.getDiffusivity', 'KAZE_DiffusivityType', ['/C', '/V', '/PV'], [], 'KAZE::DiffusivityType', ''], dict(AKAZE= classinfo))

        expected_output = ["getDiffusivity(): number;"]
        codegen = NodejsWrapperGenerator()
        codegen.parser = hdr_parser.CppHeaderParser(generate_umat_decls=True, generate_gpumat_decls=True)
        codegen.classes=dict(AKAZE= classinfo)
        codegen.add_enum("cv.KAZE.DiffusivityType", ['enum cv.KAZE.DiffusivityType', '', [], [['const cv.KAZE.DIFF_PM_G1', '0', [], [], None, ''], ['const cv.KAZE.DIFF_PM_G2', '1', [], [], None, ''], ['const cv.KAZE.DIFF_WEICKERT', '2', [], [], None, ''], ['const cv.KAZE.DIFF_CHARBONNIER', '3', [], [], None, '']], None, ''])
        self.assertEqual(funcinfo.gen_ts_typings(codegen), expected_output)

    def test_gen_ts_typings_Algorithm_write(self):
        classinfo = ClassInfo('cv.Algorithm', ['class cv.Algorithm', '', [], [], None, '@brief This is a base class for all more or less complex algorithms in OpenCV\n\nespecially for classes of algorithms, for which there can be multiple implementations. The examples\nare stereo correspondence (for which there are algorithms like block matching, semi-global block\nmatching, graph-cut etc.), background subtraction (which can be done using mixture-of-gaussians\nmodels, codebook-based algorithm etc.), optical flow (block matching, Lucas-Kanade, Horn-Schunck\netc.).\n\nHere is example of SimpleBlobDetector use in your application via Algorithm interface:\n@snippet snippets/core_various.cpp Algorithm'])
        funcinfo = FuncInfo('Algorithm', 'write', 'cv::Algorithm::write', False, 'cv', False)
        classes = dict(Algorithm=classinfo)

        funcinfo.add_variant( ['cv.Algorithm.write', 'void', ['/C'], [['FileStorage', 'fs', '', ['/Ref']], ['String', 'name', '', ['/C', '/Ref']]], 'void', '* @overload'], classes)
        funcinfo.add_variant(['cv.Algorithm.write', 'void', ['/C', '/V'], [['FileStorage', 'fs', '', ['/Ref']]], 'void', '@brief Stores algorithm parameters in a file storage'], classes)

        expected_output = set(["write(fs: FileStorage, name: String): null;","write(fs: FileStorage): null;"])
        codegen = NodejsWrapperGenerator()
        codegen.parser = hdr_parser.CppHeaderParser(generate_umat_decls=True, generate_gpumat_decls=True)
        codegen.classes=classes
        # codegen.add_enum("cv.KAZE.DiffusivityType", ['enum cv.KAZE.DiffusivityType', '', [], [['const cv.KAZE.DIFF_PM_G1', '0', [], [], None, ''], ['const cv.KAZE.DIFF_PM_G2', '1', [], [], None, ''], ['const cv.KAZE.DIFF_WEICKERT', '2', [], [], None, ''], ['const cv.KAZE.DIFF_CHARBONNIER', '3', [], [], None, '']], None, ''])
        self.assertEqual(set(funcinfo.gen_ts_typings(codegen)), expected_output)
        


if __name__ == '__main__':
    unittest.main()


