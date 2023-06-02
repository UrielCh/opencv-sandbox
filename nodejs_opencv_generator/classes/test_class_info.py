import unittest
from .func_info import FuncInfo 
from .class_info import ClassInfo
from .nodejs_wrapper_generator import NodejsWrapperGenerator
from .. import hdr_parser

class TestClassInfo(unittest.TestCase):

	def test_gen_ts_typings_BOWKMeansTrainer(self):
		classinfo = ClassInfo('cv.BOWKMeansTrainer', ['class cv.BOWKMeansTrainer', ': cv::BOWTrainer', [], [], None, '@brief kmeans -based class to train visual vocabulary using the *bag of visual words* approach. :'])
		classes =  dict(BOWKMeansTrainer = classinfo)
		funcinfo_cstr = FuncInfo('BOWKMeansTrainer', 'BOWKMeansTrainer', 'cv::BOWKMeansTrainer::BOWKMeansTrainer', True, 'cv', False)
		funcinfo_cstr.add_variant(['cv.BOWKMeansTrainer.BOWKMeansTrainer', '', [], [['int', 'clusterCount', '', []], ['TermCriteria', 'termcrit', 'TermCriteria()', ['/C', '/Ref']], ['int', 'attempts', '3', []], ['int', 'flags', 'KMEANS_PP_CENTERS', []]], None, '@brief The constructor.\n\n    @see cv::kmeans'], classes)
		classinfo.constructor = funcinfo_cstr
		funcinfo = FuncInfo('BOWKMeansTrainer', 'cluster', 'cv::BOWKMeansTrainer::cluster', False, 'cv', False)

		funcinfo.add_variant(['cv.BOWKMeansTrainer.cluster', 'Mat', ['/C', '/V'], [['Mat', 'descriptors', '', ['/C', '/Ref']]], 'Mat', ''], classes)
		funcinfo.add_variant(['cv.BOWKMeansTrainer.cluster', 'Mat', ['/C', '/V'], [], 'Mat', ''], classes)

		classinfo.methods.setdefault('cluster', funcinfo)
		classinfo.methods.setdefault('cluster', funcinfo)
		codegen = NodejsWrapperGenerator()
		codegen.parser = hdr_parser.CppHeaderParser(generate_umat_decls=True, generate_gpumat_decls=True)
		codegen.classes=classes

		expected_output = """
class BOWKMeansTrainer{
	constructor(clusterCount: number, opts?: {termcrit?: TermCriteria, attempts?: number, flags?: number}): null;
	cluster(): Mat;
	cluster(descriptors: Mat): Mat;
}
"""    
		self.assertEqual(classinfo.gen_ts_typings(codegen), expected_output)

if __name__ == '__main__':
	unittest.main()


 