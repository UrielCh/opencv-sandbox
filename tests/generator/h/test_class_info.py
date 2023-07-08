import unittest
from nodejs_opencv_generator.classes.func_info import FuncInfo 
from nodejs_opencv_generator.classes.class_info import ClassInfo
from nodejs_opencv_generator.classes.nodejs_wrapper_generator import NodejsWrapperGenerator
from nodejs_opencv_generator import hdr_parser

class TestClassInfo(unittest.TestCase):

	def test_gen_h_AKAZE(self):
		class_info = ClassInfo('cv.AKAZE', ['class cv.AKAZE', ': cv::Feature2D', [], [], None, '@brief Class implementing the AKAZE keypoint detector and descriptor extractor, described in @cite ANB13.\n\n@details AKAZE descriptors can only be used with KAZE or AKAZE keypoints. This class is thread-safe.\n\n@note When you need descriptors use Feature2D::detectAndCompute, which\nprovides better performance. When using Feature2D::detect followed by\nFeature2D::compute scale space pyramid is computed twice.\n\n@note AKAZE implements T-API. When image is passed as UMat some parts of the algorithm\nwill use OpenCL.\n\n@note [ANB13] Fast Explicit Diffusion for Accelerated Features in Nonlinear\nScale Spaces. Pablo F. Alcantarilla, Jesús Nuevo and Adrien Bartoli. In\nBritish Machine Vision Conference (BMVC), Bristol, UK, September 2013.'])
		known_classes=dict(AKAZE= class_info)

		funcinfocreate = FuncInfo("AKAZE","create","cv::AKAZE::create",False,"cv",True)
		class_info.methods.setdefault('create', funcinfocreate)
		decl =  ['cv.AKAZE.create', 'Ptr_AKAZE', ['/S'], [['AKAZE_DescriptorType', 'descriptor_type', 'AKAZE::DESCRIPTOR_MLDB', []], ['int', 'descriptor_size', '0', []], ['int', 'descriptor_channels', '3', []], ['float', 'threshold', '0.001f', []], ['int', 'nOctaves', '4', []], ['int', 'nOctaveLayers', '4', []], ['KAZE_DiffusivityType', 'diffusivity', 'KAZE::DIFF_PM_G2', []]], 'Ptr<AKAZE>', '@brief The AKAZE constructor\n\n    @param descriptor_type Type of the extracted descriptor: DESCRIPTOR_KAZE,\n    DESCRIPTOR_KAZE_UPRIGHT, DESCRIPTOR_MLDB or DESCRIPTOR_MLDB_UPRIGHT.\n    @param descriptor_size Size of the descriptor in bits. 0 -\\> Full size\n    @param descriptor_channels Number of channels in the descriptor (1, 2, 3)\n    @param threshold Detector response threshold to accept point\n    @param nOctaves Maximum octave evolution of the image\n    @param nOctaveLayers Default number of sublevels per scale level\n    @param diffusivity Diffusivity type. DIFF_PM_G1, DIFF_PM_G2, DIFF_WEICKERT or\n    DIFF_CHARBONNIER']
		funcinfocreate.add_variant(decl,known_classes,False)
		funcinfosetDescriptorType = FuncInfo("AKAZE","setDescriptorType","setDescriptorType",False,"cv",False)
		decl =  ['cv.AKAZE.setDescriptorType', 'void', ['/V', '/PV'], [['AKAZE_DescriptorType', 'dtype', '', []]], 'void', '']
		funcinfosetDescriptorType.add_variant(decl,known_classes,False)
		class_info.methods.setdefault('setDescriptorType', funcinfosetDescriptorType)
		funcinfogetDescriptorType = FuncInfo("AKAZE","getDescriptorType","getDescriptorType",False,"cv",False)
		decl =  ['cv.AKAZE.getDescriptorType', 'AKAZE_DescriptorType', ['/C', '/V', '/PV'], [], 'AKAZE::DescriptorType', '']
		funcinfogetDescriptorType.add_variant(decl,known_classes,False)
		class_info.methods.setdefault('getDescriptorType', funcinfogetDescriptorType)
		funcinfosetDescriptorSize = FuncInfo("AKAZE","setDescriptorSize","setDescriptorSize",False,"cv",False)
		decl =  ['cv.AKAZE.setDescriptorSize', 'void', ['/V', '/PV'], [['int', 'dsize', '', []]], 'void', '']
		funcinfosetDescriptorSize.add_variant(decl,known_classes,False)
		class_info.methods.setdefault('setDescriptorSize', funcinfosetDescriptorSize)
		funcinfogetDescriptorSize = FuncInfo("AKAZE","getDescriptorSize","getDescriptorSize",False,"cv",False)
		decl =  ['cv.AKAZE.getDescriptorSize', 'int', ['/C', '/V', '/PV'], [], 'int', '']
		funcinfogetDescriptorSize.add_variant(decl,known_classes,False)
		class_info.methods.setdefault('getDescriptorSize', funcinfogetDescriptorSize)
		funcinfosetDescriptorChannels = FuncInfo("AKAZE","setDescriptorChannels","setDescriptorChannels",False,"cv",False)
		decl =  ['cv.AKAZE.setDescriptorChannels', 'void', ['/V', '/PV'], [['int', 'dch', '', []]], 'void', '']
		funcinfosetDescriptorChannels.add_variant(decl,known_classes,False)
		class_info.methods.setdefault('setDescriptorChannels', funcinfosetDescriptorChannels)
		funcinfogetDescriptorChannels = FuncInfo("AKAZE","getDescriptorChannels","getDescriptorChannels",False,"cv",False)
		decl =  ['cv.AKAZE.getDescriptorChannels', 'int', ['/C', '/V', '/PV'], [], 'int', '']
		funcinfogetDescriptorChannels.add_variant(decl,known_classes,False)
		class_info.methods.setdefault('getDescriptorChannels', funcinfogetDescriptorChannels)
		funcinfosetThreshold = FuncInfo("AKAZE","setThreshold","setThreshold",False,"cv",False)
		decl =  ['cv.AKAZE.setThreshold', 'void', ['/V', '/PV'], [['double', 'threshold', '', []]], 'void', '']
		funcinfosetThreshold.add_variant(decl,known_classes,False)
		class_info.methods.setdefault('setThreshold', funcinfosetThreshold)
		funcinfogetThreshold = FuncInfo("AKAZE","getThreshold","getThreshold",False,"cv",False)
		decl =  ['cv.AKAZE.getThreshold', 'double', ['/C', '/V', '/PV'], [], 'double', '']
		funcinfogetThreshold.add_variant(decl,known_classes,False)
		class_info.methods.setdefault('getThreshold', funcinfogetThreshold)
		funcinfosetNOctaves = FuncInfo("AKAZE","setNOctaves","setNOctaves",False,"cv",False)
		decl =  ['cv.AKAZE.setNOctaves', 'void', ['/V', '/PV'], [['int', 'octaves', '', []]], 'void', '']
		funcinfosetNOctaves.add_variant(decl,known_classes,False)
		class_info.methods.setdefault('setNOctaves', funcinfosetNOctaves)
		funcinfogetNOctaves = FuncInfo("AKAZE","getNOctaves","getNOctaves",False,"cv",False)
		decl =  ['cv.AKAZE.getNOctaves', 'int', ['/C', '/V', '/PV'], [], 'int', '']
		funcinfogetNOctaves.add_variant(decl,known_classes,False)
		class_info.methods.setdefault('getNOctaves', funcinfogetNOctaves)
		funcinfosetNOctaveLayers = FuncInfo("AKAZE","setNOctaveLayers","setNOctaveLayers",False,"cv",False)
		decl =  ['cv.AKAZE.setNOctaveLayers', 'void', ['/V', '/PV'], [['int', 'octaveLayers', '', []]], 'void', '']
		funcinfosetNOctaveLayers.add_variant(decl,known_classes,False)
		class_info.methods.setdefault('setNOctaveLayers', funcinfosetNOctaveLayers)
		funcinfogetNOctaveLayers = FuncInfo("AKAZE","getNOctaveLayers","getNOctaveLayers",False,"cv",False)
		decl =  ['cv.AKAZE.getNOctaveLayers', 'int', ['/C', '/V', '/PV'], [], 'int', '']
		funcinfogetNOctaveLayers.add_variant(decl,known_classes,False)
		class_info.methods.setdefault('getNOctaveLayers', funcinfogetNOctaveLayers)
		funcinfosetDiffusivity = FuncInfo("AKAZE","setDiffusivity","setDiffusivity",False,"cv",False)
		decl =  ['cv.AKAZE.setDiffusivity', 'void', ['/V', '/PV'], [['KAZE_DiffusivityType', 'diff', '', []]], 'void', '']
		funcinfosetDiffusivity.add_variant(decl,known_classes,False)
		class_info.methods.setdefault('setDiffusivity', funcinfosetDiffusivity)
		funcinfogetDiffusivity = FuncInfo("AKAZE","getDiffusivity","getDiffusivity",False,"cv",False)
		decl =  ['cv.AKAZE.getDiffusivity', 'KAZE_DiffusivityType', ['/C', '/V', '/PV'], [], 'KAZE::DiffusivityType', '']
		funcinfogetDiffusivity.add_variant(decl,known_classes,False)
		class_info.methods.setdefault('getDiffusivity', funcinfogetDiffusivity)
		funcinfogetDefaultName = FuncInfo("AKAZE","getDefaultName","getDefaultName",False,"cv",False)
		decl =  ['cv.AKAZE.getDefaultName', 'String', ['/C', '/V'], [], 'String', '']
		funcinfogetDefaultName.add_variant(decl,known_classes,False)
		class_info.methods.setdefault('getDefaultName', funcinfogetDefaultName)



		codegen = NodejsWrapperGenerator()
		codegen.parser = hdr_parser.CppHeaderParser(generate_umat_decls=True, generate_gpumat_decls=True)
		codegen.classes=known_classes
		codegen.add_enum('cv.AKAZE.DescriptorType',['enum cv.AKAZE.DescriptorType', '', [], [['const cv.AKAZE.DESCRIPTOR_KAZE_UPRIGHT', '2', [], [], None, ''], ['const cv.AKAZE.DESCRIPTOR_KAZE', '3', [], [], None, ''], ['const cv.AKAZE.DESCRIPTOR_MLDB_UPRIGHT', '4', [], [], None, ''], ['const cv.AKAZE.DESCRIPTOR_MLDB', '5', [], [], None, '']], None, ''])
		codegen.add_enum('cv.KAZE.DiffusivityType', ['enum cv.KAZE.DiffusivityType', '', [], [['const cv.KAZE.DIFF_PM_G1', '0', [], [], None, ''], ['const cv.KAZE.DIFF_PM_G2', '1', [], [], None, ''], ['const cv.KAZE.DIFF_WEICKERT', '2', [], [], None, ''], ['const cv.KAZE.DIFF_CHARBONNIER', '3', [], [], None, '']], None, ''])
		fd = open('tests/generator/h/AKAZE.h', 'r')

		expected_output = fd.read()
		fd.close()
		generated = class_info.gen_h(codegen)
		
		self.assertEqual(generated, expected_output)

	if __name__ == '__main__':
		unittest.main()


	