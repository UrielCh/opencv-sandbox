declare namespace cv {

	class AKAZE{
		static create(opts?: {descriptor_type?: number, descriptor_size?: number, descriptor_channels?: number, threshold?: number, nOctaves?: number, nOctaveLayers?: number, diffusivity?: number}): AKAZE;
		setDescriptorType(dtype: number): null;
		getDescriptorType(): number;
		setDescriptorSize(dsize: number): null;
		getDescriptorSize(): number;
		setDescriptorChannels(dch: number): null;
		getDescriptorChannels(): number;
		setThreshold(threshold: number): null;
		getThreshold(): number;
		setNOctaves(octaves: number): null;
		getNOctaves(): number;
		setNOctaveLayers(octaveLayers: number): null;
		getNOctaveLayers(): number;
		setDiffusivity(diff: number): null;
		getDiffusivity(): number;
		getDefaultName(): String;
	}
	
	class AffineFeature{
		static create(backend: Feature2D, opts?: {maxTilt?: number, minTilt?: number, tiltStep?: number, rotateStepBase?: number}): AffineFeature;
		setViewParams(tilts: number[], rolls: number[]): null;
		getViewParams(tilts: number[], rolls: number[]): null;
		getDefaultName(): String;
	}
	
	class AgastFeatureDetector{
		static create(opts?: {threshold?: number, nonmaxSuppression?: boolean, type?: number}): AgastFeatureDetector;
		setThreshold(threshold: number): null;
		getThreshold(): number;
		setNonmaxSuppression(f: boolean): null;
		getNonmaxSuppression(): boolean;
		setType(type: number): null;
		getType(): number;
		getDefaultName(): String;
	}
	
	class Algorithm{
		clear(): null;
		write(fs: FileStorage): null;
		write(fs: FileStorage, name: String): null;
		read(fn: FileNode): null;
		empty(): boolean;
		save(filename: String): null;
		getDefaultName(): String;
	}
	
	class AlignExposures{
		process(src: Mat[], dst: Mat[], times: Mat, response: Mat): null;
	}
	
	class AlignMTB{
		process(src: Mat[], dst: Mat[]): null;
		process(src: Mat[], dst: Mat[], times: Mat, response: Mat): null;
		calculateShift(img0: Mat, img1: Mat): Point;
		shiftMat(src: Mat, dst: Mat, shift: Point): null;
		computeBitmaps(img: Mat, tb: Mat, eb: Mat): null;
		getMaxBits(): number;
		setMaxBits(max_bits: number): null;
		getExcludeRange(): number;
		setExcludeRange(exclude_range: number): null;
		getCut(): boolean;
		setCut(value: boolean): null;
	}
	
	class AsyncArray{
		constructor(): null;
		release(): null;
		get(dst: Mat): null;
		get(dst: Mat, timeoutNs: number): boolean;
		wait_for(timeoutNs: number): boolean;
		valid(): boolean;
	}
	
	class BFMatcher{
		constructor(opts?: {normType?: number, crossCheck?: boolean}): null;
		static create(opts?: {normType?: number, crossCheck?: boolean}): BFMatcher;
	}
	
	class BOWImgDescriptorExtractor{
		constructor(dextractor: DescriptorExtractor, dmatcher: DescriptorMatcher): null;
		setVocabulary(vocabulary: Mat): null;
		getVocabulary(): Mat;
		compute(image: Mat, keypoints: KeyPoint[], imgDescriptor: Mat): null;
		descriptorSize(): number;
		descriptorType(): number;
	}
	
	class BOWKMeansTrainer{
		constructor(clusterCount: number, opts?: {termcrit?: TermCriteria, attempts?: number, flags?: number}): null;
		cluster(): Mat;
		cluster(descriptors: Mat): Mat;
	}
	
	class BOWTrainer{
		add(descriptors: Mat): null;
		getDescriptors(): Mat[];
		descriptorsCount(): number;
		clear(): null;
		cluster(): Mat;
		cluster(descriptors: Mat): Mat;
	}
	
	class BRISK{
		static create(opts?: {thresh?: number, octaves?: number, patternScale?: number}): BRISK;
		static create(radiusList: number[], numberList: number[], opts?: {dMax?: number, dMin?: number, indexChange?: number[]}): BRISK;
		static create(thresh: number, octaves: number, radiusList: number[], numberList: number[], opts?: {dMax?: number, dMin?: number, indexChange?: number[]}): BRISK;
		getDefaultName(): String;
		setThreshold(threshold: number): null;
		getThreshold(): number;
		setOctaves(octaves: number): null;
		getOctaves(): number;
		setPatternScale(patternScale: number): null;
		getPatternScale(): number;
	}
	
	class BackgroundSubtractor{
		apply(image: Mat, fgmask: Mat, opts?: {learningRate?: number}): null;
		getBackgroundImage(backgroundImage: Mat): null;
	}
	
	class BackgroundSubtractorKNN{
		getHistory(): number;
		setHistory(history: number): null;
		getNSamples(): number;
		setNSamples(_nN: number): null;
		getDist2Threshold(): number;
		setDist2Threshold(_dist2Threshold: number): null;
		getkNNSamples(): number;
		setkNNSamples(_nkNN: number): null;
		getDetectShadows(): boolean;
		setDetectShadows(detectShadows: boolean): null;
		getShadowValue(): number;
		setShadowValue(value: number): null;
		getShadowThreshold(): number;
		setShadowThreshold(threshold: number): null;
	}
	
	class BackgroundSubtractorMOG2{
		getHistory(): number;
		setHistory(history: number): null;
		getNMixtures(): number;
		setNMixtures(nmixtures: number): null;
		getBackgroundRatio(): number;
		setBackgroundRatio(ratio: number): null;
		getVarThreshold(): number;
		setVarThreshold(varThreshold: number): null;
		getVarThresholdGen(): number;
		setVarThresholdGen(varThresholdGen: number): null;
		getVarInit(): number;
		setVarInit(varInit: number): null;
		getVarMin(): number;
		setVarMin(varMin: number): null;
		getVarMax(): number;
		setVarMax(varMax: number): null;
		getComplexityReductionThreshold(): number;
		setComplexityReductionThreshold(ct: number): null;
		getDetectShadows(): boolean;
		setDetectShadows(detectShadows: boolean): null;
		getShadowValue(): number;
		setShadowValue(value: number): null;
		getShadowThreshold(): number;
		setShadowThreshold(threshold: number): null;
		apply(image: Mat, fgmask: Mat, opts?: {learningRate?: number}): null;
	}
	
	class BaseCascadeClassifier{
	}
	
	class CLAHE{
		apply(src: Mat, dst: Mat): null;
		setClipLimit(clipLimit: number): null;
		getClipLimit(): number;
		setTilesGridSize(tileGridSize: Size): null;
		getTilesGridSize(): Size;
		collectGarbage(): null;
	}
	
	class CalibrateCRF{
		process(src: Mat[], dst: Mat, times: Mat): null;
	}
	
	class CalibrateDebevec{
		getLambda(): number;
		setLambda(lambda: number): null;
		getSamples(): number;
		setSamples(samples: number): null;
		getRandom(): boolean;
		setRandom(random: boolean): null;
	}
	
	class CalibrateRobertson{
		getMaxIter(): number;
		setMaxIter(max_iter: number): null;
		getThreshold(): number;
		setThreshold(threshold: number): null;
		getRadiance(): Mat;
	}
	
	class CascadeClassifier{
		constructor(filename: String): null;
		constructor(): null;
		empty(): boolean;
		load(filename: String): boolean;
		read(node: FileNode): boolean;
		detectMultiScale(image: Mat, objects: Rect[], opts?: {scaleFactor?: number, minNeighbors?: number, flags?: number, minSize?: Size, maxSize?: Size}): null;
		detectMultiScale2(image: Mat, objects: Rect[], numDetections: number[], opts?: {scaleFactor?: number, minNeighbors?: number, flags?: number, minSize?: Size, maxSize?: Size}): null;
		detectMultiScale3(image: Mat, objects: Rect[], rejectLevels: number[], levelWeights: number[], opts?: {scaleFactor?: number, minNeighbors?: number, flags?: number, minSize?: Size, maxSize?: Size, outputRejectLevels?: boolean}): null;
		isOldFormatCascade(): boolean;
		getOriginalWindowSize(): Size;
		getFeatureType(): number;
		static convert(oldcascade: String, newcascade: String): boolean;
	}
	
	class CirclesGridFinderParameters{
		constructor(): null;
	}
	
	class DISOpticalFlow{
		getFinestScale(): number;
		setFinestScale(val: number): null;
		getPatchSize(): number;
		setPatchSize(val: number): null;
		getPatchStride(): number;
		setPatchStride(val: number): null;
		getGradientDescentIterations(): number;
		setGradientDescentIterations(val: number): null;
		getVariationalRefinementIterations(): number;
		setVariationalRefinementIterations(val: number): null;
		getVariationalRefinementAlpha(): number;
		setVariationalRefinementAlpha(val: number): null;
		getVariationalRefinementDelta(): number;
		setVariationalRefinementDelta(val: number): null;
		getVariationalRefinementGamma(): number;
		setVariationalRefinementGamma(val: number): null;
		getUseMeanNormalization(): boolean;
		setUseMeanNormalization(val: boolean): null;
		getUseSpatialPropagation(): boolean;
		setUseSpatialPropagation(val: boolean): null;
		static create(opts?: {preset?: number}): DISOpticalFlow;
	}
	
	class DMatch{
		constructor(_queryIdx: number, _trainIdx: number, _distance: number): null;
		constructor(): null;
		constructor(_queryIdx: number, _trainIdx: number, _imgIdx: number, _distance: number): null;
	}
	
	class DenseOpticalFlow{
		calc(I0: Mat, I1: Mat, flow: Mat): null;
		collectGarbage(): null;
	}
	
	class DescriptorMatcher{
		add(descriptors: Mat[]): null;
		getTrainDescriptors(): Mat[];
		clear(): null;
		empty(): boolean;
		isMaskSupported(): boolean;
		train(): null;
		match(queryDescriptors: Mat, matches: DMatch[], opts?: {masks?: Mat[]}): null;
		match(queryDescriptors: Mat, trainDescriptors: Mat, matches: DMatch[], opts?: {mask?: Mat}): null;
		knnMatch(queryDescriptors: Mat, matches: DMatch[][], k: number, opts?: {masks?: Mat[], compactResult?: boolean}): null;
		knnMatch(queryDescriptors: Mat, trainDescriptors: Mat, matches: DMatch[][], k: number, opts?: {mask?: Mat, compactResult?: boolean}): null;
		radiusMatch(queryDescriptors: Mat, matches: DMatch[][], maxDistance: number, opts?: {masks?: Mat[], compactResult?: boolean}): null;
		radiusMatch(queryDescriptors: Mat, trainDescriptors: Mat, matches: DMatch[][], maxDistance: number, opts?: {mask?: Mat, compactResult?: boolean}): null;
		write(fileName: String): null;
		write(fs: FileStorage, name: String): null;
		read(arg1: FileNode): null;
		read(fileName: String): null;
		clone(opts?: {emptyTrainData?: boolean}): DescriptorMatcher;
		static create(descriptorMatcherType: String): DescriptorMatcher;
		static create(matcherType: number): DescriptorMatcher;
	}
	
	class FaceDetectorYN{
		setInputSize(input_size: Size): null;
		getInputSize(): Size;
		setScoreThreshold(score_threshold: number): null;
		getScoreThreshold(): number;
		setNMSThreshold(nms_threshold: number): null;
		getNMSThreshold(): number;
		setTopK(top_k: number): null;
		getTopK(): number;
		detect(image: Mat, faces: Mat): number;
		static create(model: String, config: String, input_size: Size, opts?: {score_threshold?: number, nms_threshold?: number, top_k?: number, backend_id?: number, target_id?: number}): FaceDetectorYN;
	}
	
	class FaceRecognizerSF{
		alignCrop(src_img: Mat, face_box: Mat, aligned_img: Mat): null;
		feature(aligned_img: Mat, face_feature: Mat): null;
		match(face_feature1: Mat, face_feature2: Mat, opts?: {dis_type?: number}): number;
		static create(model: String, config: String, opts?: {backend_id?: number, target_id?: number}): FaceRecognizerSF;
	}
	
	class FarnebackOpticalFlow{
		getNumLevels(): number;
		setNumLevels(numLevels: number): null;
		getPyrScale(): number;
		setPyrScale(pyrScale: number): null;
		getFastPyramids(): boolean;
		setFastPyramids(fastPyramids: boolean): null;
		getWinSize(): number;
		setWinSize(winSize: number): null;
		getNumIters(): number;
		setNumIters(numIters: number): null;
		getPolyN(): number;
		setPolyN(polyN: number): null;
		getPolySigma(): number;
		setPolySigma(polySigma: number): null;
		getFlags(): number;
		setFlags(flags: number): null;
		static create(opts?: {numLevels?: number, pyrScale?: number, fastPyramids?: boolean, winSize?: number, numIters?: number, polyN?: number, polySigma?: number, flags?: number}): FarnebackOpticalFlow;
	}
	
	class FastFeatureDetector{
		static create(opts?: {threshold?: number, nonmaxSuppression?: boolean, type?: number}): FastFeatureDetector;
		setThreshold(threshold: number): null;
		getThreshold(): number;
		setNonmaxSuppression(f: boolean): null;
		getNonmaxSuppression(): boolean;
		setType(type: number): null;
		getType(): number;
		getDefaultName(): String;
	}
	
	class Feature2D{
		detect(image: Mat, keypoints: KeyPoint[], opts?: {mask?: Mat}): null;
		detect(images: Mat[], keypoints: KeyPoint[][], opts?: {masks?: Mat[]}): null;
		compute(image: Mat, keypoints: KeyPoint[], descriptors: Mat): null;
		compute(images: Mat[], keypoints: KeyPoint[][], descriptors: Mat[]): null;
		detectAndCompute(image: Mat, mask: Mat, keypoints: KeyPoint[], descriptors: Mat, opts?: {useProvidedKeypoints?: boolean}): null;
		descriptorSize(): number;
		descriptorType(): number;
		defaultNorm(): number;
		write(fileName: String): null;
		write(fs: FileStorage, name: String): null;
		read(arg1: FileNode): null;
		read(fileName: String): null;
		empty(): boolean;
		getDefaultName(): String;
	}
	
	class FileNode{
		constructor(): null;
		getNode(nodename: False): FileNode;
		at(i: number): FileNode;
		keys(): String[];
		type(): number;
		empty(): boolean;
		isNone(): boolean;
		isSeq(): boolean;
		isMap(): boolean;
		isInt(): boolean;
		isReal(): boolean;
		isString(): boolean;
		isNamed(): boolean;
		name(): string;
		size(): number;
		rawSize(): number;
		real(): number;
		string(): string;
		mat(): Mat;
	}
	
	class FileStorage{
		constructor(): null;
		constructor(filename: String, flags: number, opts?: {encoding?: String}): null;
		open(filename: String, flags: number, opts?: {encoding?: String}): boolean;
		isOpened(): boolean;
		release(): null;
		releaseAndGetString(): String;
		getFirstTopLevelNode(): FileNode;
		root(opts?: {streamidx?: number}): FileNode;
		getNode(nodename: False): FileNode;
		write(name: String, val: Mat): null;
		write(name: String, val: String): null;
		write(name: String, val: String[]): null;
		write(name: String, val: number): null;
		writeComment(comment: String, opts?: {append?: boolean}): null;
		startWriteStruct(name: String, flags: number, opts?: {typeName?: String}): null;
		endWriteStruct(): null;
		getFormat(): number;
	}
	
	class FlannBasedMatcher{
		constructor(opts?: {indexParams?: flann::IndexParams, searchParams?: flann::SearchParams}): null;
		static create(): FlannBasedMatcher;
	}
	
	class GArrayDesc{
	}
	
	class GArrayT{
		constructor(type: number): null;
		type(): number;
	}
	
	class GCompileArg{
		constructor(arg: gapi_GNetPackage): null;
		constructor(arg: GKernelPackage): null;
		constructor(arg: gapi_streaming_queue_capacity): null;
	}
	
	class GComputation{
		constructor(ins: GProtoInputArgs, outs: GProtoOutputArgs): null;
		constructor(in: GMat, out: GMat): null;
		constructor(in: GMat, out: GScalar): null;
		constructor(in1: GMat, in2: GMat, out: GMat): null;
		apply(callback: detail_ExtractArgsCallback, opts?: {args?: GCompileArgs}): GRunArgs;
		compileStreaming(callback: detail_ExtractMetaCallback, opts?: {args?: GCompileArgs}): GStreamingCompiled;
		compileStreaming(in_metas: GMetaArgs, opts?: {args?: GCompileArgs}): GStreamingCompiled;
		compileStreaming(opts?: {args?: GCompileArgs}): GStreamingCompiled;
	}
	
	class GFTTDetector{
		static create(maxCorners: number, qualityLevel: number, minDistance: number, blockSize: number, gradiantSize: number, opts?: {useHarrisDetector?: boolean, k?: number}): GFTTDetector;
		static create(opts?: {maxCorners?: number, qualityLevel?: number, minDistance?: number, blockSize?: number, useHarrisDetector?: boolean, k?: number}): GFTTDetector;
		setMaxFeatures(maxFeatures: number): null;
		getMaxFeatures(): number;
		setQualityLevel(qlevel: number): null;
		getQualityLevel(): number;
		setMinDistance(minDistance: number): null;
		getMinDistance(): number;
		setBlockSize(blockSize: number): null;
		getBlockSize(): number;
		setGradientSize(gradientSize_: number): null;
		getGradientSize(): number;
		setHarrisDetector(val: boolean): null;
		getHarrisDetector(): boolean;
		setK(k: number): null;
		getK(): number;
		getDefaultName(): String;
	}
	
	class GFrame{
		constructor(): null;
	}
	
	class GInferInputs{
		constructor(): null;
		setInput(name: string, value: GFrame): GInferInputs;
		setInput(name: string, value: GMat): GInferInputs;
	}
	
	class GInferListInputs{
		constructor(): null;
		setInput(name: string, value: GArray_GMat): GInferListInputs;
		setInput(name: string, value: GArray_Rect): GInferListInputs;
	}
	
	class GInferListOutputs{
		constructor(): null;
		at(name: string): GArray_GMat;
	}
	
	class GInferOutputs{
		constructor(): null;
		at(name: string): GMat;
	}
	
	class GKernelPackage{
	}
	
	class GMat{
		constructor(): null;
	}
	
	class GMatDesc{
		constructor(d: number, dd: number[]): null;
		constructor(d: number, c: number, s: Size, opts?: {p?: boolean}): null;
		constructor(): null;
		withSizeDelta(delta: Size): GMatDesc;
		withSizeDelta(dx: number, dy: number): GMatDesc;
		withSize(sz: Size): GMatDesc;
		withDepth(ddepth: number): GMatDesc;
		withType(ddepth: number, dchan: number): GMatDesc;
		asPlanar(): GMatDesc;
		asPlanar(planes: number): GMatDesc;
		asInterleaved(): GMatDesc;
	}
	
	class GOpaqueDesc{
	}
	
	class GOpaqueT{
		constructor(type: number): null;
		type(): number;
	}
	
	class GScalar{
		constructor(): null;
		constructor(s: Scalar): null;
	}
	
	class GScalarDesc{
	}
	
	class GStreamingCompiled{
		constructor(): null;
		setSource(callback: detail_ExtractArgsCallback): null;
		start(): null;
		pull(): tuple_bool_and_util_variant_GRunArgs_and_GOptRunArgs;
		stop(): null;
		running(): boolean;
	}
	
	class GeneralizedHough{
		setTemplate(edges: Mat, dx: Mat, dy: Mat, opts?: {templCenter?: Point}): null;
		setTemplate(templ: Mat, opts?: {templCenter?: Point}): null;
		detect(edges: Mat, dx: Mat, dy: Mat, positions: Mat, opts?: {votes?: Mat}): null;
		detect(image: Mat, positions: Mat, opts?: {votes?: Mat}): null;
		setCannyLowThresh(cannyLowThresh: number): null;
		getCannyLowThresh(): number;
		setCannyHighThresh(cannyHighThresh: number): null;
		getCannyHighThresh(): number;
		setMinDist(minDist: number): null;
		getMinDist(): number;
		setDp(dp: number): null;
		getDp(): number;
		setMaxBufferSize(maxBufferSize: number): null;
		getMaxBufferSize(): number;
	}
	
	class GeneralizedHoughBallard{
		setLevels(levels: number): null;
		getLevels(): number;
		setVotesThreshold(votesThreshold: number): null;
		getVotesThreshold(): number;
	}
	
	class GeneralizedHoughGuil{
		setXi(xi: number): null;
		getXi(): number;
		setLevels(levels: number): null;
		getLevels(): number;
		setAngleEpsilon(angleEpsilon: number): null;
		getAngleEpsilon(): number;
		setMinAngle(minAngle: number): null;
		getMinAngle(): number;
		setMaxAngle(maxAngle: number): null;
		getMaxAngle(): number;
		setAngleStep(angleStep: number): null;
		getAngleStep(): number;
		setAngleThresh(angleThresh: number): null;
		getAngleThresh(): number;
		setMinScale(minScale: number): null;
		getMinScale(): number;
		setMaxScale(maxScale: number): null;
		getMaxScale(): number;
		setScaleStep(scaleStep: number): null;
		getScaleStep(): number;
		setScaleThresh(scaleThresh: number): null;
		getScaleThresh(): number;
		setPosThresh(posThresh: number): null;
		getPosThresh(): number;
	}
	
	class HOGDescriptor{
		constructor(_winSize: Size, _blockSize: Size, _blockStride: Size, _cellSize: Size, _nbins: number, opts?: {_derivAperture?: number, _winSigma?: number, _histogramNormType?: number, _L2HysThreshold?: number, _gammaCorrection?: boolean, _nlevels?: number, _signedGradient?: boolean}): null;
		constructor(): null;
		constructor(filename: String): null;
		getDescriptorSize(): number;
		checkDetectorSize(): boolean;
		getWinSigma(): number;
		setSVMDetector(svmdetector: Mat): null;
		load(filename: String, opts?: {objname?: String}): boolean;
		save(filename: String, opts?: {objname?: String}): null;
		compute(img: Mat, descriptors: number[], opts?: {winStride?: Size, padding?: Size, locations?: Point[]}): null;
		detect(img: Mat, foundLocations: Point[], weights: number[], opts?: {hitThreshold?: number, winStride?: Size, padding?: Size, searchLocations?: Point[]}): null;
		detectMultiScale(img: Mat, foundLocations: Rect[], foundWeights: number[], opts?: {hitThreshold?: number, winStride?: Size, padding?: Size, scale?: number, groupThreshold?: number, useMeanshiftGrouping?: boolean}): null;
		computeGradient(img: Mat, grad: Mat, angleOfs: Mat, opts?: {paddingTL?: Size, paddingBR?: Size}): null;
		static getDefaultPeopleDetector(): number[];
		static getDaimlerPeopleDetector(): number[];
	}
	
	class KAZE{
		static create(opts?: {extended?: boolean, upright?: boolean, threshold?: number, nOctaves?: number, nOctaveLayers?: number, diffusivity?: number}): KAZE;
		setExtended(extended: boolean): null;
		getExtended(): boolean;
		setUpright(upright: boolean): null;
		getUpright(): boolean;
		setThreshold(threshold: number): null;
		getThreshold(): number;
		setNOctaves(octaves: number): null;
		getNOctaves(): number;
		setNOctaveLayers(octaveLayers: number): null;
		getNOctaveLayers(): number;
		setDiffusivity(diff: number): null;
		getDiffusivity(): number;
		getDefaultName(): String;
	}
	
	class KalmanFilter{
		constructor(): null;
		constructor(dynamParams: number, measureParams: number, opts?: {controlParams?: number, type?: number}): null;
		predict(opts?: {control?: Mat}): Mat;
		correct(measurement: Mat): Mat;
	}
	
	class KeyPoint{
		constructor(): null;
		constructor(x: number, y: number, size: number, opts?: {angle?: number, response?: number, octave?: number, class_id?: number}): null;
		static convert(keypoints: KeyPoint[], points2f: Point2f[], opts?: {keypointIndexes?: number[]}): null;
		static convert(points2f: Point2f[], keypoints: KeyPoint[], opts?: {size?: number, response?: number, octave?: number, class_id?: number}): null;
		static overlap(kp1: KeyPoint, kp2: KeyPoint): number;
	}
	
	class LineSegmentDetector{
		detect(image: Mat, lines: Mat, opts?: {width?: Mat, prec?: Mat, nfa?: Mat}): null;
		drawSegments(image: Mat, lines: Mat): null;
		compareSegments(size: Size, lines1: Mat, lines2: Mat, opts?: {image?: Mat}): number;
	}
	
	class MSER{
		static create(opts?: {delta?: number, min_area?: number, max_area?: number, max_variation?: number, min_diversity?: number, max_evolution?: number, area_threshold?: number, min_margin?: number, edge_blur_size?: number}): MSER;
		detectRegions(image: Mat, msers: Point[][], bboxes: Rect[]): null;
		setDelta(delta: number): null;
		getDelta(): number;
		setMinArea(minArea: number): null;
		getMinArea(): number;
		setMaxArea(maxArea: number): null;
		getMaxArea(): number;
		setMaxVariation(maxVariation: number): null;
		getMaxVariation(): number;
		setMinDiversity(minDiversity: number): null;
		getMinDiversity(): number;
		setMaxEvolution(maxEvolution: number): null;
		getMaxEvolution(): number;
		setAreaThreshold(areaThreshold: number): null;
		getAreaThreshold(): number;
		setMinMargin(min_margin: number): null;
		getMinMargin(): number;
		setEdgeBlurSize(edge_blur_size: number): null;
		getEdgeBlurSize(): number;
		setPass2Only(f: boolean): null;
		getPass2Only(): boolean;
		getDefaultName(): String;
	}
	
	class MergeDebevec{
		process(src: Mat[], dst: Mat, times: Mat): null;
		process(src: Mat[], dst: Mat, times: Mat, response: Mat): null;
	}
	
	class MergeExposures{
		process(src: Mat[], dst: Mat, times: Mat, response: Mat): null;
	}
	
	class MergeMertens{
		process(src: Mat[], dst: Mat): null;
		process(src: Mat[], dst: Mat, times: Mat, response: Mat): null;
		getContrastWeight(): number;
		setContrastWeight(contrast_weiht: number): null;
		getSaturationWeight(): number;
		setSaturationWeight(saturation_weight: number): null;
		getExposureWeight(): number;
		setExposureWeight(exposure_weight: number): null;
	}
	
	class MergeRobertson{
		process(src: Mat[], dst: Mat, times: Mat): null;
		process(src: Mat[], dst: Mat, times: Mat, response: Mat): null;
	}
	
	class Moments{
	}
	
	class ORB{
		static create(opts?: {nfeatures?: number, scaleFactor?: number, nlevels?: number, edgeThreshold?: number, firstLevel?: number, WTA_K?: number, scoreType?: number, patchSize?: number, fastThreshold?: number}): ORB;
		setMaxFeatures(maxFeatures: number): null;
		getMaxFeatures(): number;
		setScaleFactor(scaleFactor: number): null;
		getScaleFactor(): number;
		setNLevels(nlevels: number): null;
		getNLevels(): number;
		setEdgeThreshold(edgeThreshold: number): null;
		getEdgeThreshold(): number;
		setFirstLevel(firstLevel: number): null;
		getFirstLevel(): number;
		setWTA_K(wta_k: number): null;
		getWTA_K(): number;
		setScoreType(scoreType: number): null;
		getScoreType(): number;
		setPatchSize(patchSize: number): null;
		getPatchSize(): number;
		setFastThreshold(fastThreshold: number): null;
		getFastThreshold(): number;
		getDefaultName(): String;
	}
	
	class QRCodeDetector{
		constructor(): null;
		setEpsX(epsX: number): null;
		setEpsY(epsY: number): null;
		setUseAlignmentMarkers(useAlignmentMarkers: boolean): null;
		detect(img: Mat, points: Mat): boolean;
		decode(img: Mat, points: Mat, opts?: {straight_qrcode?: Mat}): string;
		decodeCurved(img: Mat, points: Mat, opts?: {straight_qrcode?: Mat}): String;
		detectAndDecode(img: Mat, opts?: {points?: Mat, straight_qrcode?: Mat}): string;
		detectAndDecodeCurved(img: Mat, opts?: {points?: Mat, straight_qrcode?: Mat}): string;
		detectMulti(img: Mat, points: Mat): boolean;
		decodeMulti(img: Mat, points: Mat, decoded_info: string[], opts?: {straight_qrcode?: Mat[]}): boolean;
		detectAndDecodeMulti(img: Mat, decoded_info: string[], opts?: {points?: Mat, straight_qrcode?: Mat[]}): boolean;
	}
	
	class QRCodeEncoder{
		static create(opts?: {parameters?: QRCodeEncoder_Params}): QRCodeEncoder;
		encode(encoded_info: String, qrcode: Mat): null;
		encodeStructuredAppend(encoded_info: String, qrcodes: Mat[]): null;
	}
		namespace QRCodeEncoder {

		class Params{
			constructor(): null;
		}
			}

	class SIFT{
		static create(nfeatures: number, nOctaveLayers: number, contrastThreshold: number, edgeThreshold: number, sigma: number, descriptorType: number): SIFT;
		static create(opts?: {nfeatures?: number, nOctaveLayers?: number, contrastThreshold?: number, edgeThreshold?: number, sigma?: number}): SIFT;
		getDefaultName(): String;
		setNFeatures(maxFeatures: number): null;
		getNFeatures(): number;
		setNOctaveLayers(nOctaveLayers: number): null;
		getNOctaveLayers(): number;
		setContrastThreshold(contrastThreshold: number): null;
		getContrastThreshold(): number;
		setEdgeThreshold(edgeThreshold: number): null;
		getEdgeThreshold(): number;
		setSigma(sigma: number): null;
		getSigma(): number;
	}
	
	class SimpleBlobDetector{
		static create(opts?: {parameters?: SimpleBlobDetector_Params}): SimpleBlobDetector;
		setParams(params: SimpleBlobDetector_Params): null;
		getParams(): SimpleBlobDetector_Params;
		getDefaultName(): String;
		getBlobContours(): Point[][];
	}
		namespace SimpleBlobDetector {

		class Params{
			constructor(): null;
		}
			}

	class SparseOpticalFlow{
		calc(prevImg: Mat, nextImg: Mat, prevPts: Mat, nextPts: Mat, status: Mat, opts?: {err?: Mat}): null;
	}
	
	class SparsePyrLKOpticalFlow{
		getWinSize(): Size;
		setWinSize(winSize: Size): null;
		getMaxLevel(): number;
		setMaxLevel(maxLevel: number): null;
		getTermCriteria(): TermCriteria;
		setTermCriteria(crit: TermCriteria): null;
		getFlags(): number;
		setFlags(flags: number): null;
		getMinEigThreshold(): number;
		setMinEigThreshold(minEigThreshold: number): null;
		static create(opts?: {winSize?: Size, maxLevel?: number, crit?: TermCriteria, flags?: number, minEigThreshold?: number}): SparsePyrLKOpticalFlow;
	}
	
	class StereoBM{
		getPreFilterType(): number;
		setPreFilterType(preFilterType: number): null;
		getPreFilterSize(): number;
		setPreFilterSize(preFilterSize: number): null;
		getPreFilterCap(): number;
		setPreFilterCap(preFilterCap: number): null;
		getTextureThreshold(): number;
		setTextureThreshold(textureThreshold: number): null;
		getUniquenessRatio(): number;
		setUniquenessRatio(uniquenessRatio: number): null;
		getSmallerBlockSize(): number;
		setSmallerBlockSize(blockSize: number): null;
		getROI1(): Rect;
		setROI1(roi1: Rect): null;
		getROI2(): Rect;
		setROI2(roi2: Rect): null;
		static create(opts?: {numDisparities?: number, blockSize?: number}): StereoBM;
	}
	
	class StereoMatcher{
		compute(left: Mat, right: Mat, disparity: Mat): null;
		getMinDisparity(): number;
		setMinDisparity(minDisparity: number): null;
		getNumDisparities(): number;
		setNumDisparities(numDisparities: number): null;
		getBlockSize(): number;
		setBlockSize(blockSize: number): null;
		getSpeckleWindowSize(): number;
		setSpeckleWindowSize(speckleWindowSize: number): null;
		getSpeckleRange(): number;
		setSpeckleRange(speckleRange: number): null;
		getDisp12MaxDiff(): number;
		setDisp12MaxDiff(disp12MaxDiff: number): null;
	}
	
	class StereoSGBM{
		getPreFilterCap(): number;
		setPreFilterCap(preFilterCap: number): null;
		getUniquenessRatio(): number;
		setUniquenessRatio(uniquenessRatio: number): null;
		getP1(): number;
		setP1(P1: number): null;
		getP2(): number;
		setP2(P2: number): null;
		getMode(): number;
		setMode(mode: number): null;
		static create(opts?: {minDisparity?: number, numDisparities?: number, blockSize?: number, P1?: number, P2?: number, disp12MaxDiff?: number, preFilterCap?: number, uniquenessRatio?: number, speckleWindowSize?: number, speckleRange?: number, mode?: number}): StereoSGBM;
	}
	
	class Subdiv2D{
		constructor(): null;
		constructor(rect: Rect): null;
		initDelaunay(rect: Rect): null;
		insert(pt: Point2f): number;
		insert(ptvec: Point2f[]): null;
		locate(pt: Point2f, edge: number, vertex: number): number;
		findNearest(pt: Point2f, opts?: {nearestPt?: Point2f}): number;
		getEdgeList(edgeList: Vec4f[]): null;
		getLeadingEdgeList(leadingEdgeList: number[]): null;
		getTriangleList(triangleList: Vec6f[]): null;
		getVoronoiFacetList(idx: number[], facetList: Point2f[][], facetCenters: Point2f[]): null;
		getVertex(vertex: number, opts?: {firstEdge?: number}): Point2f;
		getEdge(edge: number, nextEdgeType: number): number;
		nextEdge(edge: number): number;
		rotateEdge(edge: number, rotate: number): number;
		symEdge(edge: number): number;
		edgeOrg(edge: number, opts?: {orgpt?: Point2f}): number;
		edgeDst(edge: number, opts?: {dstpt?: Point2f}): number;
	}
	
	class TickMeter{
		constructor(): null;
		start(): null;
		stop(): null;
		getTimeTicks(): int64;
		getTimeMicro(): number;
		getTimeMilli(): number;
		getTimeSec(): number;
		getCounter(): int64;
		getFPS(): number;
		getAvgTimeSec(): number;
		getAvgTimeMilli(): number;
		reset(): null;
	}
	
	class Tonemap{
		process(src: Mat, dst: Mat): null;
		getGamma(): number;
		setGamma(gamma: number): null;
	}
	
	class TonemapDrago{
		getSaturation(): number;
		setSaturation(saturation: number): null;
		getBias(): number;
		setBias(bias: number): null;
	}
	
	class TonemapMantiuk{
		getScale(): number;
		setScale(scale: number): null;
		getSaturation(): number;
		setSaturation(saturation: number): null;
	}
	
	class TonemapReinhard{
		getIntensity(): number;
		setIntensity(intensity: number): null;
		getLightAdaptation(): number;
		setLightAdaptation(light_adapt: number): null;
		getColorAdaptation(): number;
		setColorAdaptation(color_adapt: number): null;
	}
	
	class Tracker{
		init(image: Mat, boundingBox: Rect): null;
		update(image: Mat, boundingBox: Rect): boolean;
	}
	
	class TrackerCSRT{
		static create(opts?: {parameters?: TrackerCSRT_Params}): TrackerCSRT;
		setInitialMask(mask: Mat): null;
	}
		namespace TrackerCSRT {

		class Params{
			constructor(): null;
		}
			}

	class TrackerDaSiamRPN{
		static create(opts?: {parameters?: TrackerDaSiamRPN_Params}): TrackerDaSiamRPN;
		getTrackingScore(): number;
	}
		namespace TrackerDaSiamRPN {

		class Params{
			constructor(): null;
		}
			}

	class TrackerGOTURN{
		static create(opts?: {parameters?: TrackerGOTURN_Params}): TrackerGOTURN;
	}
		namespace TrackerGOTURN {

		class Params{
			constructor(): null;
		}
			}

	class TrackerKCF{
		static create(opts?: {parameters?: TrackerKCF_Params}): TrackerKCF;
	}
		namespace TrackerKCF {

		class Params{
			constructor(): null;
		}
			}

	class TrackerMIL{
		static create(opts?: {parameters?: TrackerMIL_Params}): TrackerMIL;
	}
		namespace TrackerMIL {

		class Params{
			constructor(): null;
		}
			}

	class TrackerNano{
		static create(opts?: {parameters?: TrackerNano_Params}): TrackerNano;
		getTrackingScore(): number;
	}
		namespace TrackerNano {

		class Params{
			constructor(): null;
		}
			}

	class UMat{
		constructor(opts?: {usageFlags?: number}): null;
		constructor(m: Mat, ranges: Range[]): null;
		constructor(rows: number, cols: number, type: number, opts?: {usageFlags?: number}): null;
		constructor(size: Size, type: number, s: Scalar, opts?: {usageFlags?: number}): null;
		constructor(rows: number, cols: number, type: number, s: Scalar, opts?: {usageFlags?: number}): null;
		constructor(m: Mat, roi: Rect): null;
		constructor(size: Size, type: number, opts?: {usageFlags?: number}): null;
		constructor(m: Mat, rowRange: Range, opts?: {colRange?: Range}): null;
		constructor(m: Mat): null;
		static queue(): void*;
		static context(): void*;
		get(): Mat;
		isContinuous(): boolean;
		isSubmatrix(): boolean;
		handle(accessFlags: number): void*;
	}
	
	class UsacParams{
		constructor(): null;
	}
	
	class VariationalRefinement{
		calcUV(I0: Mat, I1: Mat, flow_u: Mat, flow_v: Mat): null;
		getFixedPointIterations(): number;
		setFixedPointIterations(val: number): null;
		getSorIterations(): number;
		setSorIterations(val: number): null;
		getOmega(): number;
		setOmega(val: number): null;
		getAlpha(): number;
		setAlpha(val: number): null;
		getDelta(): number;
		setDelta(val: number): null;
		getGamma(): number;
		setGamma(val: number): null;
		static create(): VariationalRefinement;
	}
	
	class VideoCapture{
		constructor(): null;
		constructor(index: number, apiPreference: number, params: number[]): null;
		constructor(index: number, opts?: {apiPreference?: number}): null;
		constructor(filename: String, opts?: {apiPreference?: number}): null;
		constructor(filename: String, apiPreference: number, params: number[]): null;
		open(filename: String, apiPreference: number, params: number[]): boolean;
		open(filename: String, opts?: {apiPreference?: number}): boolean;
		open(index: number, apiPreference: number, params: number[]): boolean;
		open(index: number, opts?: {apiPreference?: number}): boolean;
		isOpened(): boolean;
		release(): null;
		grab(): boolean;
		retrieve(image: Mat, opts?: {flag?: number}): boolean;
		read(image: Mat): boolean;
		set(propId: number, value: number): boolean;
		get(propId: number): number;
		getBackendName(): String;
		setExceptionMode(enable: boolean): null;
		getExceptionMode(): boolean;
		static waitAny(streams: VideoCapture[], readyIndex: number[], opts?: {timeoutNs?: int64}): boolean;
	}
	
	class VideoWriter{
		constructor(filename: String, apiPreference: number, fourcc: number, fps: number, frameSize: Size, opts?: {isColor?: boolean}): null;
		constructor(): null;
		constructor(filename: String, fourcc: number, fps: number, frameSize: Size, params: number[]): null;
		constructor(filename: String, apiPreference: number, fourcc: number, fps: number, frameSize: Size, params: number[]): null;
		constructor(filename: String, fourcc: number, fps: number, frameSize: Size, opts?: {isColor?: boolean}): null;
		open(filename: String, apiPreference: number, fourcc: number, fps: number, frameSize: Size, opts?: {isColor?: boolean}): boolean;
		open(filename: String, apiPreference: number, fourcc: number, fps: number, frameSize: Size, params: number[]): boolean;
		open(filename: String, fourcc: number, fps: number, frameSize: Size, opts?: {isColor?: boolean}): boolean;
		open(filename: String, fourcc: number, fps: number, frameSize: Size, params: number[]): boolean;
		isOpened(): boolean;
		release(): null;
		write(image: Mat): null;
		set(propId: number, value: number): boolean;
		get(propId: number): number;
		static fourcc(c1: char, c2: char, c3: char, c4: char): number;
		getBackendName(): String;
	}
		namespace aruco {

		class ArucoDetector{
			constructor(opts?: {dictionary?: Dictionary, detectorParams?: DetectorParameters, refineParams?: RefineParameters}): null;
			detectMarkers(image: Mat, corners: Mat[], ids: Mat, opts?: {rejectedImgPoints?: Mat[]}): null;
			refineDetectedMarkers(image: Mat, board: Board, detectedCorners: Mat[], detectedIds: Mat, rejectedCorners: Mat[], opts?: {cameraMatrix?: Mat, distCoeffs?: Mat, recoveredIdxs?: Mat}): null;
			getDictionary(): Dictionary;
			setDictionary(dictionary: Dictionary): null;
			getDetectorParameters(): DetectorParameters;
			setDetectorParameters(detectorParameters: DetectorParameters): null;
			getRefineParameters(): RefineParameters;
			setRefineParameters(refineParameters: RefineParameters): null;
			write(fs: FileStorage, name: String): null;
			read(fn: FileNode): null;
		}
		
		class Board{
			constructor(objPoints: Mat[], dictionary: Dictionary, ids: Mat): null;
			getDictionary(): Dictionary;
			getObjPoints(): Point3f[][];
			getIds(): number[];
			getRightBottomCorner(): Point3f;
			matchImagePoints(detectedCorners: Mat[], detectedIds: Mat, objPoints: Mat, imgPoints: Mat): null;
			generateImage(outSize: Size, img: Mat, opts?: {marginSize?: number, borderBits?: number}): null;
		}
		
		class CharucoBoard{
			constructor(size: Size, squareLength: number, markerLength: number, dictionary: Dictionary, opts?: {ids?: Mat}): null;
			getChessboardSize(): Size;
			getSquareLength(): number;
			getMarkerLength(): number;
			getChessboardCorners(): Point3f[];
			checkCharucoCornersCollinear(charucoIds: Mat): boolean;
		}
		
		class CharucoDetector{
			constructor(board: CharucoBoard, opts?: {charucoParams?: CharucoParameters, detectorParams?: DetectorParameters, refineParams?: RefineParameters}): null;
			getBoard(): CharucoBoard;
			setBoard(board: CharucoBoard): null;
			getCharucoParameters(): CharucoParameters;
			setCharucoParameters(charucoParameters: CharucoParameters): null;
			getDetectorParameters(): DetectorParameters;
			setDetectorParameters(detectorParameters: DetectorParameters): null;
			getRefineParameters(): RefineParameters;
			setRefineParameters(refineParameters: RefineParameters): null;
			detectBoard(image: Mat, charucoCorners: Mat, charucoIds: Mat, opts?: {markerCorners?: Mat[], markerIds?: Mat}): null;
			detectDiamonds(image: Mat, diamondCorners: Mat[], diamondIds: Mat, opts?: {markerCorners?: Mat[], markerIds?: Mat[]}): null;
		}
		
		class CharucoParameters{
		}
		
		class DetectorParameters{
			constructor(): null;
			readDetectorParameters(fn: FileNode): boolean;
			writeDetectorParameters(fs: FileStorage, opts?: {name?: String}): boolean;
		}
		
		class Dictionary{
			constructor(bytesList: Mat, _markerSize: number, opts?: {maxcorr?: number}): null;
			constructor(): null;
			readDictionary(fn: FileNode): boolean;
			writeDictionary(fs: FileStorage, opts?: {name?: String}): null;
			identify(onlyBits: Mat, idx: number, rotation: number, maxCorrectionRate: number): boolean;
			getDistanceToId(bits: Mat, id: number, opts?: {allRotations?: boolean}): number;
			generateImageMarker(id: number, sidePixels: number, _img: Mat, opts?: {borderBits?: number}): null;
			static getByteListFromBits(bits: Mat): Mat;
			static getBitsFromByteList(byteList: Mat, markerSize: number): Mat;
		}
		
		class GridBoard{
			constructor(size: Size, markerLength: number, markerSeparation: number, dictionary: Dictionary, opts?: {ids?: Mat}): null;
			getGridSize(): Size;
			getMarkerLength(): number;
			getMarkerSeparation(): number;
		}
		
		class RefineParameters{
			constructor(opts?: {minRepDistance?: number, errorCorrectionRate?: number, checkAllOrders?: boolean}): null;
			readRefineParameters(fn: FileNode): boolean;
			writeRefineParameters(fs: FileStorage, opts?: {name?: String}): boolean;
		}
			}
	namespace barcode {

		class BarcodeDetector{
			constructor(opts?: {prototxt_path?: string, model_path?: string}): null;
			detect(img: Mat, points: Mat): boolean;
			decode(img: Mat, points: Mat, decoded_info: string[], decoded_type: BarcodeType[]): boolean;
			detectAndDecode(img: Mat, decoded_info: string[], decoded_type: BarcodeType[], opts?: {points?: Mat}): boolean;
		}
			}
	namespace ccm {

		class ColorCorrectionModel{
			constructor(src: Mat, constcolor: CONST_COLOR): null;
			constructor(src: Mat, colors: Mat, ref_cs: COLOR_SPACE): null;
			constructor(src: Mat, colors: Mat, ref_cs: COLOR_SPACE, colored: Mat): null;
			setColorSpace(cs: COLOR_SPACE): null;
			setCCM_TYPE(ccm_type: CCM_TYPE): null;
			setDistance(distance: DISTANCE_TYPE): null;
			setLinear(linear_type: LINEAR_TYPE): null;
			setLinearGamma(gamma: number): null;
			setLinearDegree(deg: number): null;
			setSaturatedThreshold(lower: number, upper: number): null;
			setWeightsList(weights_list: Mat): null;
			setWeightCoeff(weights_coeff: number): null;
			setInitialMethod(initial_method_type: INITIAL_METHOD_TYPE): null;
			setMaxCount(max_count: number): null;
			setEpsilon(epsilon: number): null;
			run(): null;
			getCCM(): Mat;
			getLoss(): number;
			get_src_rgbl(): Mat;
			get_dst_rgbl(): Mat;
			getMask(): Mat;
			getWeights(): Mat;
			infer(img: Mat, opts?: {islinear?: boolean}): Mat;
		}
			}
	namespace cuda {

		class BufferPool{
			constructor(stream: Stream): null;
			getBuffer(rows: number, cols: number, type: number): GpuMat;
			getBuffer(size: Size, type: number): GpuMat;
			getAllocator(): GpuMat::Allocator;
		}
		
		class DeviceInfo{
			constructor(): null;
			constructor(device_id: number): null;
			deviceID(): number;
			totalGlobalMem(): number;
			sharedMemPerBlock(): number;
			regsPerBlock(): number;
			warpSize(): number;
			memPitch(): number;
			maxThreadsPerBlock(): number;
			maxThreadsDim(): Vec3i;
			maxGridSize(): Vec3i;
			clockRate(): number;
			totalConstMem(): number;
			majorVersion(): number;
			minorVersion(): number;
			textureAlignment(): number;
			texturePitchAlignment(): number;
			multiProcessorCount(): number;
			kernelExecTimeoutEnabled(): boolean;
			integrated(): boolean;
			canMapHostMemory(): boolean;
			computeMode(): DeviceInfo_ComputeMode;
			maxTexture1D(): number;
			maxTexture1DMipmap(): number;
			maxTexture1DLinear(): number;
			maxTexture2D(): Vec2i;
			maxTexture2DMipmap(): Vec2i;
			maxTexture2DLinear(): Vec3i;
			maxTexture2DGather(): Vec2i;
			maxTexture3D(): Vec3i;
			maxTextureCubemap(): number;
			maxTexture1DLayered(): Vec2i;
			maxTexture2DLayered(): Vec3i;
			maxTextureCubemapLayered(): Vec2i;
			maxSurface1D(): number;
			maxSurface2D(): Vec2i;
			maxSurface3D(): Vec3i;
			maxSurface1DLayered(): Vec2i;
			maxSurface2DLayered(): Vec3i;
			maxSurfaceCubemap(): number;
			maxSurfaceCubemapLayered(): Vec2i;
			surfaceAlignment(): number;
			concurrentKernels(): boolean;
			ECCEnabled(): boolean;
			pciBusID(): number;
			pciDeviceID(): number;
			pciDomainID(): number;
			tccDriver(): boolean;
			asyncEngineCount(): number;
			unifiedAddressing(): boolean;
			memoryClockRate(): number;
			memoryBusWidth(): number;
			l2CacheSize(): number;
			maxThreadsPerMultiProcessor(): number;
			queryMemory(totalMemory: number, freeMemory: number): null;
			freeMemory(): number;
			totalMemory(): number;
			isCompatible(): boolean;
		}
		
		class Event{
			constructor(opts?: {flags?: Event_CreateFlags}): null;
			record(opts?: {stream?: Stream}): null;
			queryIfComplete(): boolean;
			waitForCompletion(): null;
			static elapsedTime(start: Event, end: Event): number;
		}
		
		class GpuData{
		}
		
		class GpuMat{
			constructor(rows: number, cols: number, type: number, s: Scalar, opts?: {allocator?: GpuMat_Allocator*}): null;
			constructor(arr: cuda::GpuMat, opts?: {allocator?: GpuMat_Allocator*}): null;
			constructor(m: GpuMat, roi: Rect): null;
			constructor(m: GpuMat): null;
			constructor(arr: Mat, opts?: {allocator?: GpuMat_Allocator*}): null;
			constructor(rows: number, cols: number, type: number, opts?: {allocator?: GpuMat_Allocator*}): null;
			constructor(size: Size, type: number, opts?: {allocator?: GpuMat_Allocator*}): null;
			constructor(m: GpuMat, rowRange: Range, colRange: Range): null;
			constructor(size: Size, type: number, s: Scalar, opts?: {allocator?: GpuMat_Allocator*}): null;
			constructor(opts?: {allocator?: GpuMat_Allocator*}): null;
			static defaultAllocator(): GpuMat_Allocator*;
			static setDefaultAllocator(allocator: GpuMat_Allocator*): null;
			create(rows: number, cols: number, type: number): null;
			create(size: Size, type: number): null;
			release(): null;
			swap(mat: GpuMat): null;
			upload(arr: Mat): null;
			upload(arr: Mat, stream: Stream): null;
			upload(arr: cuda::GpuMat): null;
			upload(arr: cuda::GpuMat, stream: Stream): null;
			download(dst: Mat): null;
			download(dst: Mat, stream: Stream): null;
			download(dst: cuda::GpuMat): null;
			download(dst: cuda::GpuMat, stream: Stream): null;
			clone(): GpuMat;
			copyTo(dst: Mat): null;
			copyTo(dst: Mat, mask: Mat): null;
			copyTo(dst: Mat, mask: Mat, stream: Stream): null;
			copyTo(dst: Mat, stream: Stream): null;
			copyTo(dst: cuda::GpuMat): null;
			copyTo(dst: cuda::GpuMat, mask: cuda::GpuMat): null;
			copyTo(dst: cuda::GpuMat, mask: cuda::GpuMat, stream: Stream): null;
			copyTo(dst: cuda::GpuMat, stream: Stream): null;
			setTo(s: Scalar): GpuMat;
			setTo(s: Scalar, mask: Mat): GpuMat;
			setTo(s: Scalar, mask: Mat, stream: Stream): GpuMat;
			setTo(s: Scalar, mask: cuda::GpuMat): GpuMat;
			setTo(s: Scalar, mask: cuda::GpuMat, stream: Stream): GpuMat;
			setTo(s: Scalar, stream: Stream): GpuMat;
			convertTo(dst: Mat, rtype: number): null;
			convertTo(dst: Mat, rtype: number, alpha: number, beta: number, stream: Stream): null;
			convertTo(dst: Mat, rtype: number, alpha: number, opts?: {beta?: number}): null;
			convertTo(dst: Mat, rtype: number, alpha: number, stream: Stream): null;
			convertTo(dst: Mat, rtype: number, stream: Stream): null;
			convertTo(dst: cuda::GpuMat, rtype: number): null;
			convertTo(dst: cuda::GpuMat, rtype: number, alpha: number, beta: number, stream: Stream): null;
			convertTo(dst: cuda::GpuMat, rtype: number, alpha: number, opts?: {beta?: number}): null;
			convertTo(dst: cuda::GpuMat, rtype: number, alpha: number, stream: Stream): null;
			convertTo(dst: cuda::GpuMat, rtype: number, stream: Stream): null;
			assignTo(m: GpuMat, opts?: {type?: number}): null;
			row(y: number): GpuMat;
			col(x: number): GpuMat;
			rowRange(r: Range): GpuMat;
			rowRange(startrow: number, endrow: number): GpuMat;
			colRange(r: Range): GpuMat;
			colRange(startcol: number, endcol: number): GpuMat;
			reshape(cn: number, opts?: {rows?: number}): GpuMat;
			locateROI(wholeSize: Size, ofs: Point): null;
			adjustROI(dtop: number, dbottom: number, dleft: number, dright: number): GpuMat;
			isContinuous(): boolean;
			elemSize(): number;
			elemSize1(): number;
			type(): number;
			depth(): number;
			channels(): number;
			step1(): number;
			size(): Size;
			empty(): boolean;
			cudaPtr(): void*;
			updateContinuityFlag(): null;
		}
		
		class GpuMatND{
		}
				namespace GpuMat {

			class Allocator{
			}
			
		class HostMem{
			constructor(arr: cuda::GpuMat, opts?: {alloc_type?: HostMem_AllocType}): null;
			constructor(rows: number, cols: number, type: number, opts?: {alloc_type?: HostMem_AllocType}): null;
			constructor(size: Size, type: number, opts?: {alloc_type?: HostMem_AllocType}): null;
			constructor(arr: Mat, opts?: {alloc_type?: HostMem_AllocType}): null;
			constructor(opts?: {alloc_type?: HostMem_AllocType}): null;
			swap(b: HostMem): null;
			clone(): HostMem;
			create(rows: number, cols: number, type: number): null;
			reshape(cn: number, opts?: {rows?: number}): HostMem;
			createMatHeader(): Mat;
			isContinuous(): boolean;
			elemSize(): number;
			elemSize1(): number;
			type(): number;
			depth(): number;
			channels(): number;
			step1(): number;
			size(): Size;
			empty(): boolean;
		}
		
		class SURF_CUDA{
			static create(_hessianThreshold: number, opts?: {_nOctaves?: number, _nOctaveLayers?: number, _extended?: boolean, _keypointsRatio?: number, _upright?: boolean}): SURF::CUDA;
			descriptorSize(): number;
			defaultNorm(): number;
			downloadKeypoints(keypointsGPU: GpuMat, keypoints: KeyPoint[]): null;
			detect(img: GpuMat, mask: GpuMat, keypoints: GpuMat): null;
			detectWithDescriptors(img: GpuMat, mask: GpuMat, keypoints: GpuMat, descriptors: GpuMat, opts?: {useProvidedKeypoints?: boolean}): null;
		}
		
		class Stream{
			constructor(cudaFlags: number): null;
			constructor(): null;
			constructor(allocator: GpuMat::Allocator): null;
			queryIfComplete(): boolean;
			waitForCompletion(): null;
			waitEvent(event: Event): null;
			static Null(): Stream;
			cudaPtr(): void*;
		}
		
		class TargetArchs{
			static has(major: number, minor: number): boolean;
			static hasPtx(major: number, minor: number): boolean;
			static hasBin(major: number, minor: number): boolean;
			static hasEqualOrLessPtx(major: number, minor: number): boolean;
			static hasEqualOrGreater(major: number, minor: number): boolean;
			static hasEqualOrGreaterPtx(major: number, minor: number): boolean;
			static hasEqualOrGreaterBin(major: number, minor: number): boolean;
		}
				}
	}
	namespace dnn {

		class ClassificationModel{
			constructor(network: Net): null;
			constructor(model: String, opts?: {config?: String}): null;
			setEnableSoftmaxPostProcessing(enable: boolean): ClassificationModel;
			getEnableSoftmaxPostProcessing(): boolean;
			classify(frame: Mat, classId: number, conf: number): null;
		}
		
		class DetectionModel{
			constructor(network: Net): null;
			constructor(model: String, opts?: {config?: String}): null;
			setNmsAcrossClasses(value: boolean): DetectionModel;
			getNmsAcrossClasses(): boolean;
			detect(frame: Mat, classIds: number[], confidences: number[], boxes: Rect[], opts?: {confThreshold?: number, nmsThreshold?: number}): null;
		}
		
		class DictValue{
			constructor(s: String): null;
			constructor(p: number): null;
			constructor(i: number): null;
			isInt(): boolean;
			isString(): boolean;
			isReal(): boolean;
			getIntValue(opts?: {idx?: number}): number;
			getRealValue(opts?: {idx?: number}): number;
			getStringValue(opts?: {idx?: number}): String;
		}
		
		class KeypointsModel{
			constructor(network: Net): null;
			constructor(model: String, opts?: {config?: String}): null;
			estimate(frame: Mat, opts?: {thresh?: number}): Point2f[];
		}
		
		class Layer{
			finalize(inputs: Mat[], outputs: Mat[]): null;
			run(inputs: Mat[], outputs: Mat[], internals: Mat[]): null;
			outputNameToIndex(outputName: String): number;
		}
		
		class Model{
			constructor(network: Net): null;
			constructor(model: String, opts?: {config?: String}): null;
			setInputSize(size: Size): Model;
			setInputSize(width: number, height: number): Model;
			setInputMean(mean: Scalar): Model;
			setInputScale(scale: number): Model;
			setInputCrop(crop: boolean): Model;
			setInputSwapRB(swapRB: boolean): Model;
			setInputParams(opts?: {scale?: number, size?: Size, mean?: Scalar, swapRB?: boolean, crop?: boolean}): null;
			predict(frame: Mat, outs: Mat[]): null;
			setPreferableBackend(backendId: number): Model;
			setPreferableTarget(targetId: number): Model;
		}
		
		class Net{
			constructor(): null;
			static readFromModelOptimizer(bufferModelConfig: uchar[], bufferWeights: uchar[]): Net;
			static readFromModelOptimizer(xml: String, bin: String): Net;
			empty(): boolean;
			dump(): String;
			dumpToFile(path: String): null;
			getLayerId(layer: String): number;
			getLayerNames(): String[];
			getLayer(layerId: LayerId): Layer;
			getLayer(layerId: number): Layer;
			getLayer(layerName: String): Layer;
			connect(outPin: String, inpPin: String): null;
			setInputsNames(inputBlobNames: String[]): null;
			setInputShape(inputName: String, shape: MatShape): null;
			forward(opts?: {outputName?: String}): Mat;
			forward(outputBlobs: Mat[], opts?: {outputName?: String}): null;
			forward(outputBlobs: Mat[], outBlobNames: String[]): null;
			forwardAsync(opts?: {outputName?: String}): AsyncArray;
			forwardAndRetrieve(outputBlobs: Mat[][], outBlobNames: String[]): null;
			quantize(calibData: Mat[], inputsDtype: number, outputsDtype: number, opts?: {perChannel?: boolean}): Net;
			getInputDetails(scales: number[], zeropoints: number[]): null;
			getOutputDetails(scales: number[], zeropoints: number[]): null;
			setHalideScheduler(scheduler: String): null;
			setPreferableBackend(backendId: number): null;
			setPreferableTarget(targetId: number): null;
			setInput(blob: Mat, opts?: {name?: String, scalefactor?: number, mean?: Scalar}): null;
			setParam(layer: number, numParam: number, blob: Mat): null;
			setParam(layerName: String, numParam: number, blob: Mat): null;
			getParam(layer: number, opts?: {numParam?: number}): Mat;
			getParam(layerName: String, opts?: {numParam?: number}): Mat;
			getUnconnectedOutLayers(): number[];
			getUnconnectedOutLayersNames(): String[];
			getLayersShapes(netInputShape: MatShape, layersIds: number[], inLayersShapes: MatShape[][], outLayersShapes: MatShape[][]): null;
			getLayersShapes(netInputShapes: MatShape[], layersIds: number[], inLayersShapes: MatShape[][], outLayersShapes: MatShape[][]): null;
			getFLOPS(layerId: number, netInputShape: MatShape): int64;
			getFLOPS(layerId: number, netInputShapes: MatShape[]): int64;
			getFLOPS(netInputShape: MatShape): int64;
			getFLOPS(netInputShapes: MatShape[]): int64;
			getLayerTypes(layersTypes: String[]): null;
			getLayersCount(layerType: String): number;
			getMemoryConsumption(layerId: number, netInputShape: MatShape, weights: number, blobs: number): null;
			getMemoryConsumption(layerId: number, netInputShapes: MatShape[], weights: number, blobs: number): null;
			getMemoryConsumption(netInputShape: MatShape, weights: number, blobs: number): null;
			enableFusion(fusion: boolean): null;
			enableWinograd(useWinograd: boolean): null;
			getPerfProfile(timings: number[]): int64;
		}
		
		class SegmentationModel{
			constructor(network: Net): null;
			constructor(model: String, opts?: {config?: String}): null;
			segment(frame: Mat, mask: Mat): null;
		}
		
		class TextDetectionModel{
			detect(frame: Mat, detections: Point[][]): null;
			detect(frame: Mat, detections: Point[][], confidences: number[]): null;
			detectTextRectangles(frame: Mat, detections: RotatedRect[]): null;
			detectTextRectangles(frame: Mat, detections: RotatedRect[], confidences: number[]): null;
		}
		
		class TextDetectionModel_DB{
			constructor(model: string, opts?: {config?: string}): null;
			constructor(network: Net): null;
			setBinaryThreshold(binaryThreshold: number): TextDetectionModel_DB;
			getBinaryThreshold(): number;
			setPolygonThreshold(polygonThreshold: number): TextDetectionModel_DB;
			getPolygonThreshold(): number;
			setUnclipRatio(unclipRatio: number): TextDetectionModel_DB;
			getUnclipRatio(): number;
			setMaxCandidates(maxCandidates: number): TextDetectionModel_DB;
			getMaxCandidates(): number;
		}
		
		class TextDetectionModel_EAST{
			constructor(model: string, opts?: {config?: string}): null;
			constructor(network: Net): null;
			setConfidenceThreshold(confThreshold: number): TextDetectionModel_EAST;
			getConfidenceThreshold(): number;
			setNMSThreshold(nmsThreshold: number): TextDetectionModel_EAST;
			getNMSThreshold(): number;
		}
		
		class TextRecognitionModel{
			constructor(model: string, opts?: {config?: string}): null;
			constructor(network: Net): null;
			setDecodeType(decodeType: string): TextRecognitionModel;
			getDecodeType(): string;
			setDecodeOptsCTCPrefixBeamSearch(beamSize: number, opts?: {vocPruneSize?: number}): TextRecognitionModel;
			setVocabulary(vocabulary: string[]): TextRecognitionModel;
			getVocabulary(): string[];
			recognize(frame: Mat): string;
			recognize(frame: Mat, roiRects: Mat[], results: string[]): null;
		}
			}
	namespace dnn_superres {

		class DnnSuperResImpl{
			static create(): DnnSuperResImpl;
			readModel(path: String): null;
			setModel(algo: String, scale: number): null;
			setPreferableBackend(backendId: number): null;
			setPreferableTarget(targetId: number): null;
			upsample(img: Mat, result: Mat): null;
			upsampleMultioutput(img: Mat, imgs_new: Mat[], scale_factors: number[], node_names: String[]): null;
			getScale(): number;
			getAlgorithm(): String;
		}
			}
	namespace face {

		class BIF{
			getNumBands(): number;
			getNumRotations(): number;
			compute(image: Mat, features: Mat): null;
			static create(opts?: {num_bands?: number, num_rotations?: number}): BIF;
		}
		
		class BasicFaceRecognizer{
			getNumComponents(): number;
			setNumComponents(val: number): null;
			getThreshold(): number;
			setThreshold(val: number): null;
			getProjections(): Mat[];
			getLabels(): Mat;
			getEigenValues(): Mat;
			getEigenVectors(): Mat;
			getMean(): Mat;
		}
		
		class EigenFaceRecognizer{
			static create(opts?: {num_components?: number, threshold?: number}): EigenFaceRecognizer;
		}
		
		class FaceRecognizer{
			train(src: Mat[], labels: Mat): null;
			update(src: Mat[], labels: Mat): null;
			predict_label(src: Mat): number;
			predict(src: Mat, label: number, confidence: number): null;
			predict_collect(src: Mat, collector: PredictCollector): null;
			write(filename: String): null;
			read(filename: String): null;
			setLabelInfo(label: number, strInfo: String): null;
			getLabelInfo(label: number): String;
			getLabelsByString(str: String): number[];
		}
		
		class Facemark{
			loadModel(model: String): null;
			fit(image: Mat, faces: Mat, landmarks: Mat[]): boolean;
		}
		
		class FacemarkAAM{
		}
		
		class FacemarkKazemi{
		}
		
		class FacemarkLBF{
		}
		
		class FacemarkTrain{
		}
		
		class FisherFaceRecognizer{
			static create(opts?: {num_components?: number, threshold?: number}): FisherFaceRecognizer;
		}
		
		class LBPHFaceRecognizer{
			getGridX(): number;
			setGridX(val: number): null;
			getGridY(): number;
			setGridY(val: number): null;
			getRadius(): number;
			setRadius(val: number): null;
			getNeighbors(): number;
			setNeighbors(val: number): null;
			getThreshold(): number;
			setThreshold(val: number): null;
			getHistograms(): Mat[];
			getLabels(): Mat;
			static create(opts?: {radius?: number, neighbors?: number, grid_x?: number, grid_y?: number, threshold?: number}): LBPHFaceRecognizer;
		}
		
		class MACE{
			salt(passphrase: String): null;
			train(images: Mat[]): null;
			same(query: Mat): boolean;
			static load(filename: String, opts?: {objname?: String}): MACE;
			static create(opts?: {IMGSIZE?: number}): MACE;
		}
		
		class PredictCollector{
		}
		
		class StandardCollector{
			getMinLabel(): number;
			getMinDist(): number;
			getResults(opts?: {sorted?: boolean}): pair_int_and_double[];
			static create(opts?: {threshold?: number}): StandardCollector;
		}
			}
	namespace flann {

		class Index{
			constructor(): null;
			constructor(features: Mat, params: IndexParams, opts?: {distType?: cvflann_flann_distance_t}): null;
			build(features: Mat, params: IndexParams, opts?: {distType?: cvflann_flann_distance_t}): null;
			knnSearch(query: Mat, indices: Mat, dists: Mat, knn: number, opts?: {params?: SearchParams}): null;
			radiusSearch(query: Mat, indices: Mat, dists: Mat, radius: number, maxResults: number, opts?: {params?: SearchParams}): number;
			save(filename: String): null;
			load(features: Mat, filename: String): boolean;
			release(): null;
			getDistance(): cvflann_flann_distance_t;
			getAlgorithm(): cvflann_flann_algorithm_t;
		}
			}
	namespace freetype {

		class FreeType2{
			loadFontData(fontFileName: String, idx: number): null;
			setSplitNumber(num: number): null;
			putText(img: Mat, text: String, org: Point, fontHeight: number, color: Scalar, thickness: number, line_type: number, bottomLeftOrigin: boolean): null;
			getTextSize(text: String, fontHeight: number, thickness: number, baseLine: number): Size;
		}
			}
	namespace gapi {

		class GNetPackage{
			constructor(nets: GNetParam[]): null;
			constructor(): null;
		}
		
		class GNetParam{
		}
				namespace ie {

			class PyParams{
				constructor(tag: string, model: string, device: string): null;
				constructor(): null;
				constructor(tag: string, model: string, weights: string, device: string): null;
				constInput(layer_name: string, data: Mat, opts?: {hint?: TraitAs}): PyParams;
				cfgNumRequests(nireq: number): PyParams;
				cfgBatchSize(size: number): PyParams;
			}
					}
		namespace onnx {

			class PyParams{
				constructor(): null;
				constructor(tag: string, model_path: string): null;
			}
					}
		namespace streaming {

			class queue_capacity{
				constructor(opts?: {cap?: number}): null;
			}
					}
		namespace wip {

			class GOutputs{
				getGMat(): GMat;
				getGScalar(): GScalar;
				getGArray(type: number): GArrayT;
				getGOpaque(type: number): GOpaqueT;
			}
			
			class IStreamSource{
			}
						namespace draw {

				class Circle{
					constructor(center_: Point, radius_: number, color_: Scalar, opts?: {thick_?: number, lt_?: number, shift_?: number}): null;
					constructor(): null;
				}
				
				class Image{
					constructor(): null;
					constructor(org_: Point, img_: Mat, alpha_: Mat): null;
				}
				
				class Line{
					constructor(pt1_: Point, pt2_: Point, color_: Scalar, opts?: {thick_?: number, lt_?: number, shift_?: number}): null;
					constructor(): null;
				}
				
				class Mosaic{
					constructor(): null;
					constructor(mos_: Rect2i, cellSz_: number, decim_: number): null;
				}
				
				class Poly{
					constructor(points_: Point[], color_: Scalar, opts?: {thick_?: number, lt_?: number, shift_?: number}): null;
					constructor(): null;
				}
				
				class Rect{
					constructor(rect_: Rect2i, color_: Scalar, opts?: {thick_?: number, lt_?: number, shift_?: number}): null;
					constructor(): null;
				}
				
				class Text{
					constructor(text_: string, org_: Point, ff_: number, fs_: number, color_: Scalar, opts?: {thick_?: number, lt_?: number, bottom_left_origin_?: boolean}): null;
					constructor(): null;
				}
							}
			namespace gst {

				class GStreamerPipeline{
					constructor(pipeline: string): null;
				}
							}
		}
	}
	namespace img_hash {

		class AverageHash{
			static create(): AverageHash;
		}
		
		class BlockMeanHash{
			setMode(mode: number): null;
			getMean(): number[];
			static create(opts?: {mode?: number}): BlockMeanHash;
		}
		
		class ColorMomentHash{
			static create(): ColorMomentHash;
		}
		
		class ImgHashBase{
			compute(inputArr: Mat, outputArr: Mat): null;
			compare(hashOne: Mat, hashTwo: Mat): number;
		}
		
		class MarrHildrethHash{
			getAlpha(): number;
			getScale(): number;
			setKernelParam(alpha: number, scale: number): null;
			static create(opts?: {alpha?: number, scale?: number}): MarrHildrethHash;
		}
		
		class PHash{
			static create(): PHash;
		}
		
		class RadialVarianceHash{
			static create(opts?: {sigma?: number, numOfAngleLine?: number}): RadialVarianceHash;
			getNumOfAngleLine(): number;
			getSigma(): number;
			setNumOfAngleLine(value: number): null;
			setSigma(value: number): null;
		}
			}
	namespace legacy {

		class MultiTracker{
			constructor(): null;
			add(newTracker: legacy::Tracker, image: Mat, boundingBox: Rect2d): boolean;
			update(image: Mat, boundingBox: Rect2d[]): boolean;
			getObjects(): Rect2d[];
			static create(): MultiTracker;
		}
		
		class Tracker{
			init(image: Mat, boundingBox: Rect2d): boolean;
			update(image: Mat, boundingBox: Rect2d): boolean;
		}
		
		class TrackerBoosting{
			static create(): legacy::TrackerBoosting;
		}
		
		class TrackerCSRT{
			static create(): legacy::TrackerCSRT;
			setInitialMask(mask: Mat): null;
		}
		
		class TrackerKCF{
			static create(): legacy::TrackerKCF;
		}
		
		class TrackerMIL{
			static create(): legacy::TrackerMIL;
		}
		
		class TrackerMOSSE{
			static create(): legacy::TrackerMOSSE;
		}
		
		class TrackerMedianFlow{
			static create(): legacy::TrackerMedianFlow;
		}
		
		class TrackerTLD{
			static create(): legacy::TrackerTLD;
		}
			}
	namespace mcc {

		class CChecker{
			static create(): CChecker;
			setTarget(_target: TYPECHART): null;
			setBox(_box: Point2f[]): null;
			setChartsRGB(_chartsRGB: Mat): null;
			setChartsYCbCr(_chartsYCbCr: Mat): null;
			setCost(_cost: number): null;
			setCenter(_center: Point2f): null;
			getTarget(): TYPECHART;
			getBox(): Point2f[];
			getChartsRGB(): Mat;
			getChartsYCbCr(): Mat;
			getCost(): number;
			getCenter(): Point2f;
		}
		
		class CCheckerDetector{
			setNet(net: dnn_Net): boolean;
			processWithROI(image: Mat, chartType: TYPECHART, regionsOfInterest: Rect[], opts?: {nc?: number, useNet?: boolean, params?: DetectorParameters}): boolean;
			process(image: Mat, chartType: TYPECHART, opts?: {nc?: number, useNet?: boolean, params?: DetectorParameters}): boolean;
			getBestColorChecker(): mcc::CChecker;
			getListColorChecker(): Ptr_CChecker[];
			static create(): CCheckerDetector;
		}
		
		class CCheckerDraw{
			draw(img: Mat): null;
			static create(pChecker: CChecker, opts?: {color?: Scalar, thickness?: number}): CCheckerDraw;
		}
		
		class DetectorParameters{
			static create(): DetectorParameters;
		}
			}
	namespace ml {

		class ANN_MLP{
			setTrainMethod(method: number, opts?: {param1?: number, param2?: number}): null;
			getTrainMethod(): number;
			setActivationFunction(type: number, opts?: {param1?: number, param2?: number}): null;
			setLayerSizes(_layer_sizes: Mat): null;
			getLayerSizes(): Mat;
			getTermCriteria(): TermCriteria;
			setTermCriteria(val: TermCriteria): null;
			getBackpropWeightScale(): number;
			setBackpropWeightScale(val: number): null;
			getBackpropMomentumScale(): number;
			setBackpropMomentumScale(val: number): null;
			getRpropDW0(): number;
			setRpropDW0(val: number): null;
			getRpropDWPlus(): number;
			setRpropDWPlus(val: number): null;
			getRpropDWMinus(): number;
			setRpropDWMinus(val: number): null;
			getRpropDWMin(): number;
			setRpropDWMin(val: number): null;
			getRpropDWMax(): number;
			setRpropDWMax(val: number): null;
			getAnnealInitialT(): number;
			setAnnealInitialT(val: number): null;
			getAnnealFinalT(): number;
			setAnnealFinalT(val: number): null;
			getAnnealCoolingRatio(): number;
			setAnnealCoolingRatio(val: number): null;
			getAnnealItePerStep(): number;
			setAnnealItePerStep(val: number): null;
			getWeights(layerIdx: number): Mat;
			static create(): ANN::MLP;
			static load(filepath: String): ANN::MLP;
		}
		
		class Boost{
			getBoostType(): number;
			setBoostType(val: number): null;
			getWeakCount(): number;
			setWeakCount(val: number): null;
			getWeightTrimRate(): number;
			setWeightTrimRate(val: number): null;
			static create(): Boost;
			static load(filepath: String, opts?: {nodeName?: String}): Boost;
		}
		
		class DTrees{
			getMaxCategories(): number;
			setMaxCategories(val: number): null;
			getMaxDepth(): number;
			setMaxDepth(val: number): null;
			getMinSampleCount(): number;
			setMinSampleCount(val: number): null;
			getCVFolds(): number;
			setCVFolds(val: number): null;
			getUseSurrogates(): boolean;
			setUseSurrogates(val: boolean): null;
			getUse1SERule(): boolean;
			setUse1SERule(val: boolean): null;
			getTruncatePrunedTree(): boolean;
			setTruncatePrunedTree(val: boolean): null;
			getRegressionAccuracy(): number;
			setRegressionAccuracy(val: number): null;
			getPriors(): Mat;
			setPriors(val: Mat): null;
			static create(): DTrees;
			static load(filepath: String, opts?: {nodeName?: String}): DTrees;
		}
		
		class EM{
			getClustersNumber(): number;
			setClustersNumber(val: number): null;
			getCovarianceMatrixType(): number;
			setCovarianceMatrixType(val: number): null;
			getTermCriteria(): TermCriteria;
			setTermCriteria(val: TermCriteria): null;
			getWeights(): Mat;
			getMeans(): Mat;
			getCovs(covs: Mat[]): null;
			predict(samples: Mat, opts?: {results?: Mat, flags?: number}): number;
			predict2(sample: Mat, probs: Mat): Vec2d;
			trainEM(samples: Mat, opts?: {logLikelihoods?: Mat, labels?: Mat, probs?: Mat}): boolean;
			trainE(samples: Mat, means0: Mat, opts?: {covs0?: Mat, weights0?: Mat, logLikelihoods?: Mat, labels?: Mat, probs?: Mat}): boolean;
			trainM(samples: Mat, probs0: Mat, opts?: {logLikelihoods?: Mat, labels?: Mat, probs?: Mat}): boolean;
			static create(): EM;
			static load(filepath: String, opts?: {nodeName?: String}): EM;
		}
		
		class KNearest{
			getDefaultK(): number;
			setDefaultK(val: number): null;
			getIsClassifier(): boolean;
			setIsClassifier(val: boolean): null;
			getEmax(): number;
			setEmax(val: number): null;
			getAlgorithmType(): number;
			setAlgorithmType(val: number): null;
			findNearest(samples: Mat, k: number, results: Mat, opts?: {neighborResponses?: Mat, dist?: Mat}): number;
			static create(): KNearest;
			static load(filepath: String): KNearest;
		}
		
		class LogisticRegression{
			getLearningRate(): number;
			setLearningRate(val: number): null;
			getIterations(): number;
			setIterations(val: number): null;
			getRegularization(): number;
			setRegularization(val: number): null;
			getTrainMethod(): number;
			setTrainMethod(val: number): null;
			getMiniBatchSize(): number;
			setMiniBatchSize(val: number): null;
			getTermCriteria(): TermCriteria;
			setTermCriteria(val: TermCriteria): null;
			predict(samples: Mat, opts?: {results?: Mat, flags?: number}): number;
			get_learnt_thetas(): Mat;
			static create(): LogisticRegression;
			static load(filepath: String, opts?: {nodeName?: String}): LogisticRegression;
		}
		
		class NormalBayesClassifier{
			predictProb(inputs: Mat, outputs: Mat, outputProbs: Mat, opts?: {flags?: number}): number;
			static create(): NormalBayesClassifier;
			static load(filepath: String, opts?: {nodeName?: String}): NormalBayesClassifier;
		}
		
		class ParamGrid{
			static create(opts?: {minVal?: number, maxVal?: number, logstep?: number}): ParamGrid;
		}
		
		class RTrees{
			getCalculateVarImportance(): boolean;
			setCalculateVarImportance(val: boolean): null;
			getActiveVarCount(): number;
			setActiveVarCount(val: number): null;
			getTermCriteria(): TermCriteria;
			setTermCriteria(val: TermCriteria): null;
			getVarImportance(): Mat;
			getVotes(samples: Mat, results: Mat, flags: number): null;
			getOOBError(): number;
			static create(): RTrees;
			static load(filepath: String, opts?: {nodeName?: String}): RTrees;
		}
		
		class SVM{
			getType(): number;
			setType(val: number): null;
			getGamma(): number;
			setGamma(val: number): null;
			getCoef0(): number;
			setCoef0(val: number): null;
			getDegree(): number;
			setDegree(val: number): null;
			getC(): number;
			setC(val: number): null;
			getNu(): number;
			setNu(val: number): null;
			getP(): number;
			setP(val: number): null;
			getClassWeights(): Mat;
			setClassWeights(val: Mat): null;
			getTermCriteria(): TermCriteria;
			setTermCriteria(val: TermCriteria): null;
			getKernelType(): number;
			setKernel(kernelType: number): null;
			trainAuto(samples: Mat, layout: number, responses: Mat, opts?: {kFold?: number, Cgrid?: ParamGrid, gammaGrid?: ParamGrid, pGrid?: ParamGrid, nuGrid?: ParamGrid, coeffGrid?: ParamGrid, degreeGrid?: ParamGrid, balanced?: boolean}): boolean;
			getSupportVectors(): Mat;
			getUncompressedSupportVectors(): Mat;
			getDecisionFunction(i: number, alpha: Mat, svidx: Mat): number;
			static getDefaultGridPtr(param_id: number): ParamGrid;
			static create(): SVM;
			static load(filepath: String): SVM;
		}
		
		class SVMSGD{
			getWeights(): Mat;
			getShift(): number;
			static create(): SVMSGD;
			static load(filepath: String, opts?: {nodeName?: String}): SVMSGD;
			setOptimalParameters(opts?: {svmsgdType?: number, marginType?: number}): null;
			getSvmsgdType(): number;
			setSvmsgdType(svmsgdType: number): null;
			getMarginType(): number;
			setMarginType(marginType: number): null;
			getMarginRegularization(): number;
			setMarginRegularization(marginRegularization: number): null;
			getInitialStepSize(): number;
			setInitialStepSize(InitialStepSize: number): null;
			getStepDecreasingPower(): number;
			setStepDecreasingPower(stepDecreasingPower: number): null;
			getTermCriteria(): TermCriteria;
			setTermCriteria(val: TermCriteria): null;
		}
		
		class StatModel{
			getVarCount(): number;
			empty(): boolean;
			isTrained(): boolean;
			isClassifier(): boolean;
			train(samples: Mat, layout: number, responses: Mat): boolean;
			train(trainData: TrainData, opts?: {flags?: number}): boolean;
			calcError(data: TrainData, test: boolean, resp: Mat): number;
			predict(samples: Mat, opts?: {results?: Mat, flags?: number}): number;
		}
		
		class TrainData{
			getLayout(): number;
			getNTrainSamples(): number;
			getNTestSamples(): number;
			getNSamples(): number;
			getNVars(): number;
			getNAllVars(): number;
			getSample(varIdx: Mat, sidx: number, buf: number): null;
			getSamples(): Mat;
			getMissing(): Mat;
			getTrainSamples(opts?: {layout?: number, compressSamples?: boolean, compressVars?: boolean}): Mat;
			getTrainResponses(): Mat;
			getTrainNormCatResponses(): Mat;
			getTestResponses(): Mat;
			getTestNormCatResponses(): Mat;
			getResponses(): Mat;
			getNormCatResponses(): Mat;
			getSampleWeights(): Mat;
			getTrainSampleWeights(): Mat;
			getTestSampleWeights(): Mat;
			getVarIdx(): Mat;
			getVarType(): Mat;
			getVarSymbolFlags(): Mat;
			getResponseType(): number;
			getTrainSampleIdx(): Mat;
			getTestSampleIdx(): Mat;
			getValues(vi: number, sidx: Mat, values: number): null;
			getDefaultSubstValues(): Mat;
			getCatCount(vi: number): number;
			getClassLabels(): Mat;
			getCatOfs(): Mat;
			getCatMap(): Mat;
			setTrainTestSplit(count: number, opts?: {shuffle?: boolean}): null;
			setTrainTestSplitRatio(ratio: number, opts?: {shuffle?: boolean}): null;
			shuffleTrainTest(): null;
			getTestSamples(): Mat;
			getNames(names: String[]): null;
			static getSubVector(vec: Mat, idx: Mat): Mat;
			static getSubMatrix(matrix: Mat, idx: Mat, layout: number): Mat;
			static create(samples: Mat, layout: number, responses: Mat, opts?: {varIdx?: Mat, sampleIdx?: Mat, sampleWeights?: Mat, varType?: Mat}): TrainData;
		}
			}
	namespace ocl {

		class Device{
			constructor(): null;
			name(): String;
			extensions(): String;
			isExtensionSupported(extensionName: String): boolean;
			version(): String;
			vendorName(): String;
			OpenCL_C_Version(): String;
			OpenCLVersion(): String;
			deviceVersionMajor(): number;
			deviceVersionMinor(): number;
			driverVersion(): String;
			type(): number;
			addressBits(): number;
			available(): boolean;
			compilerAvailable(): boolean;
			linkerAvailable(): boolean;
			doubleFPConfig(): number;
			singleFPConfig(): number;
			halfFPConfig(): number;
			endianLittle(): boolean;
			errorCorrectionSupport(): boolean;
			executionCapabilities(): number;
			globalMemCacheSize(): number;
			globalMemCacheType(): number;
			globalMemCacheLineSize(): number;
			globalMemSize(): number;
			localMemSize(): number;
			localMemType(): number;
			hostUnifiedMemory(): boolean;
			imageSupport(): boolean;
			imageFromBufferSupport(): boolean;
			intelSubgroupsSupport(): boolean;
			image2DMaxWidth(): number;
			image2DMaxHeight(): number;
			image3DMaxWidth(): number;
			image3DMaxHeight(): number;
			image3DMaxDepth(): number;
			imageMaxBufferSize(): number;
			imageMaxArraySize(): number;
			vendorID(): number;
			isAMD(): boolean;
			isIntel(): boolean;
			isNVidia(): boolean;
			maxClockFrequency(): number;
			maxComputeUnits(): number;
			maxConstantArgs(): number;
			maxConstantBufferSize(): number;
			maxMemAllocSize(): number;
			maxParameterSize(): number;
			maxReadImageArgs(): number;
			maxWriteImageArgs(): number;
			maxSamplers(): number;
			maxWorkGroupSize(): number;
			maxWorkItemDims(): number;
			memBaseAddrAlign(): number;
			nativeVectorWidthChar(): number;
			nativeVectorWidthShort(): number;
			nativeVectorWidthInt(): number;
			nativeVectorWidthLong(): number;
			nativeVectorWidthFloat(): number;
			nativeVectorWidthDouble(): number;
			nativeVectorWidthHalf(): number;
			preferredVectorWidthChar(): number;
			preferredVectorWidthShort(): number;
			preferredVectorWidthInt(): number;
			preferredVectorWidthLong(): number;
			preferredVectorWidthFloat(): number;
			preferredVectorWidthDouble(): number;
			preferredVectorWidthHalf(): number;
			printfBufferSize(): number;
			profilingTimerResolution(): number;
			static getDefault(): Device;
		}
		
		class OpenCLExecutionContext{
		}
			}
	namespace plot {

		class Plot2d{
			setMinX(_plotMinX: number): null;
			setMinY(_plotMinY: number): null;
			setMaxX(_plotMaxX: number): null;
			setMaxY(_plotMaxY: number): null;
			setPlotLineWidth(_plotLineWidth: number): null;
			setNeedPlotLine(_needPlotLine: boolean): null;
			setPlotLineColor(_plotLineColor: Scalar): null;
			setPlotBackgroundColor(_plotBackgroundColor: Scalar): null;
			setPlotAxisColor(_plotAxisColor: Scalar): null;
			setPlotGridColor(_plotGridColor: Scalar): null;
			setPlotTextColor(_plotTextColor: Scalar): null;
			setPlotSize(_plotSizeWidth: number, _plotSizeHeight: number): null;
			setShowGrid(needShowGrid: boolean): null;
			setShowText(needShowText: boolean): null;
			setGridLinesNumber(gridLinesNumber: number): null;
			setInvertOrientation(_invertOrientation: boolean): null;
			setPointIdxToPrint(pointIdx: number): null;
			render(_plotResult: Mat): null;
			static create(data: Mat): Plot2d;
			static create(dataX: Mat, dataY: Mat): Plot2d;
		}
			}
	namespace quality {

		class QualityBRISQUE{
			compute(img: Mat): Scalar;
			compute(img: Mat, model_file_path: String, range_file_path: String): Scalar;
			static create(model: ml::SVM, range: Mat): QualityBRISQUE;
			static create(model_file_path: String, range_file_path: String): QualityBRISQUE;
			static computeFeatures(img: Mat, features: Mat): null;
		}
		
		class QualityBase{
			compute(img: Mat): Scalar;
			getQualityMap(dst: Mat): null;
			clear(): null;
			empty(): boolean;
		}
		
		class QualityGMSD{
			compute(cmp: Mat): Scalar;
			compute(ref: Mat, cmp: Mat, qualityMap: Mat): Scalar;
			empty(): boolean;
			clear(): null;
			static create(ref: Mat): QualityGMSD;
		}
		
		class QualityMSE{
			compute(cmpImgs: Mat[]): Scalar;
			compute(ref: Mat, cmp: Mat, qualityMap: Mat): Scalar;
			empty(): boolean;
			clear(): null;
			static create(ref: Mat): QualityMSE;
		}
		
		class QualityPSNR{
			static create(ref: Mat, opts?: {maxPixelValue?: number}): QualityPSNR;
			compute(cmp: Mat): Scalar;
			compute(ref: Mat, cmp: Mat, qualityMap: Mat, opts?: {maxPixelValue?: number}): Scalar;
			empty(): boolean;
			clear(): null;
			getMaxPixelValue(): number;
			setMaxPixelValue(val: number): null;
		}
		
		class QualitySSIM{
			compute(cmp: Mat): Scalar;
			compute(ref: Mat, cmp: Mat, qualityMap: Mat): Scalar;
			empty(): boolean;
			clear(): null;
			static create(ref: Mat): QualitySSIM;
		}
			}
	namespace rapid {

		class GOSTracker{
			static create(pts3d: Mat, tris: Mat, opts?: {histBins?: number, sobelThesh?: uchar}): OLSTracker;
		}
		
		class OLSTracker{
			static create(pts3d: Mat, tris: Mat, opts?: {histBins?: number, sobelThesh?: uchar}): OLSTracker;
		}
		
		class Rapid{
			static create(pts3d: Mat, tris: Mat): Rapid;
		}
		
		class Tracker{
			compute(img: Mat, num: number, len: number, K: Mat, rvec: Mat, tvec: Mat, opts?: {termcrit?: TermCriteria}): number;
			clearState(): null;
		}
			}
	namespace segmentation {

		class IntelligentScissorsMB{
			constructor(): null;
			setWeights(weight_non_edge: number, weight_gradient_direction: number, weight_gradient_magnitude: number): IntelligentScissorsMB;
			setGradientMagnitudeMaxLimit(opts?: {gradient_magnitude_threshold_max?: number}): IntelligentScissorsMB;
			setEdgeFeatureZeroCrossingParameters(opts?: {gradient_magnitude_min_value?: number}): IntelligentScissorsMB;
			setEdgeFeatureCannyParameters(threshold1: number, threshold2: number, opts?: {apertureSize?: number, L2gradient?: boolean}): IntelligentScissorsMB;
			applyImage(image: Mat): IntelligentScissorsMB;
			applyImageFeatures(non_edge: Mat, gradient_direction: Mat, gradient_magnitude: Mat, opts?: {image?: Mat}): IntelligentScissorsMB;
			buildMap(sourcePt: Point): null;
			getContour(targetPt: Point, contour: Mat, opts?: {backward?: boolean}): null;
		}
			}
	namespace text {

		class BaseOCR{
		}
		
		class ERFilter{
		}
				namespace ERFilter {

			class Callback{
			}
			
		class OCRBeamSearchDecoder{
			run(image: Mat, mask: Mat, min_confidence: number, opts?: {component_level?: number}): String;
			run(image: Mat, min_confidence: number, opts?: {component_level?: number}): String;
			static create(classifier: OCRBeamSearchDecoder::ClassifierCallback, vocabulary: string, transition_probabilities_table: Mat, emission_probabilities_table: Mat, opts?: {mode?: number, beam_size?: number}): OCRBeamSearchDecoder;
		}
				}
		namespace OCRBeamSearchDecoder {

			class ClassifierCallback{
			}
			
		class OCRHMMDecoder{
			run(image: Mat, mask: Mat, min_confidence: number, opts?: {component_level?: number}): String;
			run(image: Mat, min_confidence: number, opts?: {component_level?: number}): String;
			static create(classifier: OCRHMMDecoder::ClassifierCallback, vocabulary: String, transition_probabilities_table: Mat, emission_probabilities_table: Mat, opts?: {mode?: number}): OCRHMMDecoder;
			static create(filename: String, vocabulary: String, transition_probabilities_table: Mat, emission_probabilities_table: Mat, opts?: {mode?: number, classifier?: number}): OCRHMMDecoder;
		}
				}
		namespace OCRHMMDecoder {

			class ClassifierCallback{
			}
			
		class OCRTesseract{
			run(image: Mat, mask: Mat, min_confidence: number, opts?: {component_level?: number}): String;
			run(image: Mat, min_confidence: number, opts?: {component_level?: number}): String;
			setWhiteList(char_whitelist: String): null;
			static create(opts?: {datapath?: False, language?: False, char_whitelist?: False, oem?: number, psmode?: number}): OCRTesseract;
		}
		
		class TextDetector{
			detect(inputImage: Mat, Bbox: Rect[], confidence: number[]): null;
		}
		
		class TextDetectorCNN{
			detect(inputImage: Mat, Bbox: Rect[], confidence: number[]): null;
			static create(modelArchFilename: String, modelWeightsFilename: String): TextDetectorCNN;
		}
				}
	}
	namespace utils {

		class ClassWithKeywordProperties{
			constructor(opts?: {lambda_arg?: number, except_arg?: number}): null;
		}
				namespace nested {

			class ExportClassName{
				getIntParam(): number;
				getFloatParam(): number;
				static originalName(): string;
				static create(opts?: {params?: OriginalClassName_Params}): OriginalClassName;
			}
						namespace ExportClassName {

				class Params{
					constructor(opts?: {int_param?: number, float_param?: number}): null;
				}
							}
		}
	}
	namespace xfeatures2d {

		class AffineFeature2D{
		}
		
		class BEBLID{
			static create(scale_factor: number, opts?: {n_bits?: number}): BEBLID;
			setScaleFactor(scale_factor: number): null;
			getScaleFactor(): number;
			getDefaultName(): String;
		}
		
		class BoostDesc{
			static create(opts?: {desc?: number, use_scale_orientation?: boolean, scale_factor?: number}): BoostDesc;
			getDefaultName(): String;
			setUseScaleOrientation(use_scale_orientation: boolean): null;
			getUseScaleOrientation(): boolean;
			setScaleFactor(scale_factor: number): null;
			getScaleFactor(): number;
		}
		
		class BriefDescriptorExtractor{
			static create(opts?: {bytes?: number, use_orientation?: boolean}): BriefDescriptorExtractor;
			setDescriptorSize(bytes: number): null;
			getDescriptorSize(): number;
			setUseOrientation(use_orientation: boolean): null;
			getUseOrientation(): boolean;
			getDefaultName(): String;
		}
		
		class DAISY{
			static create(opts?: {radius?: number, q_radius?: number, q_theta?: number, q_hist?: number, norm?: DAISY_NormalizationType, H?: Mat, interpolation?: boolean, use_orientation?: boolean}): DAISY;
			setRadius(radius: number): null;
			getRadius(): number;
			setQRadius(q_radius: number): null;
			getQRadius(): number;
			setQTheta(q_theta: number): null;
			getQTheta(): number;
			setQHist(q_hist: number): null;
			getQHist(): number;
			setNorm(norm: number): null;
			getNorm(): number;
			setH(H: Mat): null;
			getH(): Mat;
			setInterpolation(interpolation: boolean): null;
			getInterpolation(): boolean;
			setUseOrientation(use_orientation: boolean): null;
			getUseOrientation(): boolean;
			getDefaultName(): String;
		}
		
		class FREAK{
			static create(opts?: {orientationNormalized?: boolean, scaleNormalized?: boolean, patternScale?: number, nOctaves?: number, selectedPairs?: number[]}): FREAK;
			setOrientationNormalized(orientationNormalized: boolean): null;
			getOrientationNormalized(): boolean;
			setScaleNormalized(scaleNormalized: boolean): null;
			getScaleNormalized(): boolean;
			setPatternScale(patternScale: number): null;
			getPatternScale(): number;
			setNOctaves(nOctaves: number): null;
			getNOctaves(): number;
			getDefaultName(): String;
		}
		
		class HarrisLaplaceFeatureDetector{
			static create(opts?: {numOctaves?: number, corn_thresh?: number, DOG_thresh?: number, maxCorners?: number, num_layers?: number}): HarrisLaplaceFeatureDetector;
			setNumOctaves(numOctaves_: number): null;
			getNumOctaves(): number;
			setCornThresh(corn_thresh_: number): null;
			getCornThresh(): number;
			setDOGThresh(DOG_thresh_: number): null;
			getDOGThresh(): number;
			setMaxCorners(maxCorners_: number): null;
			getMaxCorners(): number;
			setNumLayers(num_layers_: number): null;
			getNumLayers(): number;
			getDefaultName(): String;
		}
		
		class LATCH{
			static create(opts?: {bytes?: number, rotationInvariance?: boolean, half_ssd_size?: number, sigma?: number}): LATCH;
			setBytes(bytes: number): null;
			getBytes(): number;
			setRotationInvariance(rotationInvariance: boolean): null;
			getRotationInvariance(): boolean;
			setHalfSSDsize(half_ssd_size: number): null;
			getHalfSSDsize(): number;
			setSigma(sigma: number): null;
			getSigma(): number;
			getDefaultName(): String;
		}
		
		class LUCID{
			static create(opts?: {lucid_kernel?: number, blur_kernel?: number}): LUCID;
			setLucidKernel(lucid_kernel: number): null;
			getLucidKernel(): number;
			setBlurKernel(blur_kernel: number): null;
			getBlurKernel(): number;
			getDefaultName(): String;
		}
		
		class MSDDetector{
			static create(opts?: {m_patch_radius?: number, m_search_area_radius?: number, m_nms_radius?: number, m_nms_scale_radius?: number, m_th_saliency?: number, m_kNN?: number, m_scale_factor?: number, m_n_scales?: number, m_compute_orientation?: boolean}): MSDDetector;
			setPatchRadius(patch_radius: number): null;
			getPatchRadius(): number;
			setSearchAreaRadius(use_orientation: number): null;
			getSearchAreaRadius(): number;
			setNmsRadius(nms_radius: number): null;
			getNmsRadius(): number;
			setNmsScaleRadius(nms_scale_radius: number): null;
			getNmsScaleRadius(): number;
			setThSaliency(th_saliency: number): null;
			getThSaliency(): number;
			setKNN(kNN: number): null;
			getKNN(): number;
			setScaleFactor(scale_factor: number): null;
			getScaleFactor(): number;
			setNScales(use_orientation: number): null;
			getNScales(): number;
			setComputeOrientation(compute_orientation: boolean): null;
			getComputeOrientation(): boolean;
			getDefaultName(): String;
		}
		
		class PCTSignatures{
			static create(initSamplingPoints: Point2f[], initClusterSeedIndexes: number[]): PCTSignatures;
			static create(initSamplingPoints: Point2f[], initSeedCount: number): PCTSignatures;
			static create(opts?: {initSampleCount?: number, initSeedCount?: number, pointDistribution?: number}): PCTSignatures;
			computeSignature(image: Mat, signature: Mat): null;
			computeSignatures(images: Mat[], signatures: Mat[]): null;
			static drawSignature(source: Mat, signature: Mat, result: Mat, opts?: {radiusToShorterSideRatio?: number, borderThickness?: number}): null;
			static generateInitPoints(initPoints: Point2f[], count: number, pointDistribution: number): null;
			getSampleCount(): number;
			getGrayscaleBits(): number;
			setGrayscaleBits(grayscaleBits: number): null;
			getWindowRadius(): number;
			setWindowRadius(radius: number): null;
			getWeightX(): number;
			setWeightX(weight: number): null;
			getWeightY(): number;
			setWeightY(weight: number): null;
			getWeightL(): number;
			setWeightL(weight: number): null;
			getWeightA(): number;
			setWeightA(weight: number): null;
			getWeightB(): number;
			setWeightB(weight: number): null;
			getWeightContrast(): number;
			setWeightContrast(weight: number): null;
			getWeightEntropy(): number;
			setWeightEntropy(weight: number): null;
			getSamplingPoints(): Point2f[];
			setWeight(idx: number, value: number): null;
			setWeights(weights: number[]): null;
			setTranslation(idx: number, value: number): null;
			setTranslations(translations: number[]): null;
			setSamplingPoints(samplingPoints: Point2f[]): null;
			getInitSeedIndexes(): number[];
			setInitSeedIndexes(initSeedIndexes: number[]): null;
			getInitSeedCount(): number;
			getIterationCount(): number;
			setIterationCount(iterationCount: number): null;
			getMaxClustersCount(): number;
			setMaxClustersCount(maxClustersCount: number): null;
			getClusterMinSize(): number;
			setClusterMinSize(clusterMinSize: number): null;
			getJoiningDistance(): number;
			setJoiningDistance(joiningDistance: number): null;
			getDropThreshold(): number;
			setDropThreshold(dropThreshold: number): null;
			getDistanceFunction(): number;
			setDistanceFunction(distanceFunction: number): null;
		}
		
		class PCTSignaturesSQFD{
			static create(opts?: {distanceFunction?: number, similarityFunction?: number, similarityParameter?: number}): PCTSignaturesSQFD;
			computeQuadraticFormDistance(_signature0: Mat, _signature1: Mat): number;
			computeQuadraticFormDistances(sourceSignature: Mat, imageSignatures: Mat[], distances: number[]): null;
		}
		
		class SURF{
			static create(opts?: {hessianThreshold?: number, nOctaves?: number, nOctaveLayers?: number, extended?: boolean, upright?: boolean}): SURF;
			setHessianThreshold(hessianThreshold: number): null;
			getHessianThreshold(): number;
			setNOctaves(nOctaves: number): null;
			getNOctaves(): number;
			setNOctaveLayers(nOctaveLayers: number): null;
			getNOctaveLayers(): number;
			setExtended(extended: boolean): null;
			getExtended(): boolean;
			setUpright(upright: boolean): null;
			getUpright(): boolean;
			getDefaultName(): String;
		}
		
		class StarDetector{
			static create(opts?: {maxSize?: number, responseThreshold?: number, lineThresholdProjected?: number, lineThresholdBinarized?: number, suppressNonmaxSize?: number}): StarDetector;
			setMaxSize(_maxSize: number): null;
			getMaxSize(): number;
			setResponseThreshold(_responseThreshold: number): null;
			getResponseThreshold(): number;
			setLineThresholdProjected(_lineThresholdProjected: number): null;
			getLineThresholdProjected(): number;
			setLineThresholdBinarized(_lineThresholdBinarized: number): null;
			getLineThresholdBinarized(): number;
			setSuppressNonmaxSize(_suppressNonmaxSize: number): null;
			getSuppressNonmaxSize(): number;
			getDefaultName(): String;
		}
		
		class TBMR{
			static create(opts?: {min_area?: number, max_area_relative?: number, scale_factor?: number, n_scales?: number}): TBMR;
			setMinArea(minArea: number): null;
			getMinArea(): number;
			setMaxAreaRelative(maxArea: number): null;
			getMaxAreaRelative(): number;
			setScaleFactor(scale_factor: number): null;
			getScaleFactor(): number;
			setNScales(n_scales: number): null;
			getNScales(): number;
		}
		
		class TEBLID{
			static create(scale_factor: number, opts?: {n_bits?: number}): TEBLID;
			getDefaultName(): String;
		}
		
		class VGG{
			static create(opts?: {desc?: number, isigma?: number, img_normalize?: boolean, use_scale_orientation?: boolean, scale_factor?: number, dsc_normalize?: boolean}): VGG;
			getDefaultName(): String;
			setSigma(isigma: number): null;
			getSigma(): number;
			setUseNormalizeImage(img_normalize: boolean): null;
			getUseNormalizeImage(): boolean;
			setUseScaleOrientation(use_scale_orientation: boolean): null;
			getUseScaleOrientation(): boolean;
			setScaleFactor(scale_factor: number): null;
			getScaleFactor(): number;
			setUseNormalizeDescriptor(dsc_normalize: boolean): null;
			getUseNormalizeDescriptor(): boolean;
		}
			}
	namespace ximgproc {

		class AdaptiveManifoldFilter{
			filter(src: Mat, dst: Mat, opts?: {joint?: Mat}): null;
			collectGarbage(): null;
			static create(): AdaptiveManifoldFilter;
		}
		
		class ContourFitting{
			estimateTransformation(src: Mat, dst: Mat, alphaPhiST: Mat, dist: number, opts?: {fdContour?: boolean}): null;
			setCtrSize(n: number): null;
			setFDSize(n: number): null;
			getCtrSize(): number;
			getFDSize(): number;
		}
		
		class DTFilter{
			filter(src: Mat, dst: Mat, opts?: {dDepth?: number}): null;
		}
		
		class DisparityFilter{
			filter(disparity_map_left: Mat, left_view: Mat, filtered_disparity_map: Mat, opts?: {disparity_map_right?: Mat, ROI?: Rect, right_view?: Mat}): null;
		}
		
		class DisparityWLSFilter{
			getLambda(): number;
			setLambda(_lambda: number): null;
			getSigmaColor(): number;
			setSigmaColor(_sigma_color: number): null;
			getLRCthresh(): number;
			setLRCthresh(_LRC_thresh: number): null;
			getDepthDiscontinuityRadius(): number;
			setDepthDiscontinuityRadius(_disc_radius: number): null;
			getConfidenceMap(): Mat;
			getROI(): Rect;
		}
		
		class EdgeAwareInterpolator{
			setCostMap(_costMap: Mat): null;
			setK(_k: number): null;
			getK(): number;
			setSigma(_sigma: number): null;
			getSigma(): number;
			setLambda(_lambda: number): null;
			getLambda(): number;
			setUsePostProcessing(_use_post_proc: boolean): null;
			getUsePostProcessing(): boolean;
			setFGSLambda(_lambda: number): null;
			getFGSLambda(): number;
			setFGSSigma(_sigma: number): null;
			getFGSSigma(): number;
		}
		
		class EdgeBoxes{
			getBoundingBoxes(edge_map: Mat, orientation_map: Mat, boxes: Rect[], opts?: {scores?: Mat}): null;
			getAlpha(): number;
			setAlpha(value: number): null;
			getBeta(): number;
			setBeta(value: number): null;
			getEta(): number;
			setEta(value: number): null;
			getMinScore(): number;
			setMinScore(value: number): null;
			getMaxBoxes(): number;
			setMaxBoxes(value: number): null;
			getEdgeMinMag(): number;
			setEdgeMinMag(value: number): null;
			getEdgeMergeThr(): number;
			setEdgeMergeThr(value: number): null;
			getClusterMinMag(): number;
			setClusterMinMag(value: number): null;
			getMaxAspectRatio(): number;
			setMaxAspectRatio(value: number): null;
			getMinBoxArea(): number;
			setMinBoxArea(value: number): null;
			getGamma(): number;
			setGamma(value: number): null;
			getKappa(): number;
			setKappa(value: number): null;
		}
		
		class EdgeDrawing{
			detectEdges(src: Mat): null;
			getEdgeImage(dst: Mat): null;
			getGradientImage(dst: Mat): null;
			getSegments(): Point[][];
			getSegmentIndicesOfLines(): number[];
			detectLines(lines: Mat): null;
			detectEllipses(ellipses: Mat): null;
			setParams(parameters: EdgeDrawing_Params): null;
		}
				namespace EdgeDrawing {

			class Params{
				constructor(): null;
			}
			
		class FastBilateralSolverFilter{
			filter(src: Mat, confidence: Mat, dst: Mat): null;
		}
		
		class FastGlobalSmootherFilter{
			filter(src: Mat, dst: Mat): null;
		}
		
		class FastLineDetector{
			detect(image: Mat, lines: Mat): null;
			drawSegments(image: Mat, lines: Mat, opts?: {draw_arrow?: boolean, linecolor?: Scalar, linethickness?: number}): null;
		}
		
		class GuidedFilter{
			filter(src: Mat, dst: Mat, opts?: {dDepth?: number}): null;
		}
		
		class RFFeatureGetter{
			getFeatures(src: Mat, features: Mat, gnrmRad: number, gsmthRad: number, shrink: number, outNum: number, gradNum: number): null;
		}
		
		class RICInterpolator{
			setK(opts?: {k?: number}): null;
			getK(): number;
			setCostMap(costMap: Mat): null;
			setSuperpixelSize(opts?: {spSize?: number}): null;
			getSuperpixelSize(): number;
			setSuperpixelNNCnt(opts?: {spNN?: number}): null;
			getSuperpixelNNCnt(): number;
			setSuperpixelRuler(opts?: {ruler?: number}): null;
			getSuperpixelRuler(): number;
			setSuperpixelMode(opts?: {mode?: number}): null;
			getSuperpixelMode(): number;
			setAlpha(opts?: {alpha?: number}): null;
			getAlpha(): number;
			setModelIter(opts?: {modelIter?: number}): null;
			getModelIter(): number;
			setRefineModels(opts?: {refineModles?: boolean}): null;
			getRefineModels(): boolean;
			setMaxFlow(opts?: {maxFlow?: number}): null;
			getMaxFlow(): number;
			setUseVariationalRefinement(opts?: {use_variational_refinement?: boolean}): null;
			getUseVariationalRefinement(): boolean;
			setUseGlobalSmootherFilter(opts?: {use_FGS?: boolean}): null;
			getUseGlobalSmootherFilter(): boolean;
			setFGSLambda(opts?: {lambda?: number}): null;
			getFGSLambda(): number;
			setFGSSigma(opts?: {sigma?: number}): null;
			getFGSSigma(): number;
		}
		
		class RidgeDetectionFilter{
			static create(opts?: {ddepth?: number, dx?: number, dy?: number, ksize?: number, out_dtype?: number, scale?: number, delta?: number, borderType?: number}): RidgeDetectionFilter;
			getRidgeFilteredImage(_img: Mat, out: Mat): null;
		}
		
		class ScanSegment{
			getNumberOfSuperpixels(): number;
			iterate(img: Mat): null;
			getLabels(labels_out: Mat): null;
			getLabelContourMask(image: Mat, opts?: {thick_line?: boolean}): null;
		}
		
		class SparseMatchInterpolator{
			interpolate(from_image: Mat, from_points: Mat, to_image: Mat, to_points: Mat, dense_flow: Mat): null;
		}
		
		class StructuredEdgeDetection{
			detectEdges(src: Mat, dst: Mat): null;
			computeOrientation(src: Mat, dst: Mat): null;
			edgesNms(edge_image: Mat, orientation_image: Mat, dst: Mat, opts?: {r?: number, s?: number, m?: number, isParallel?: boolean}): null;
		}
		
		class SuperpixelLSC{
			getNumberOfSuperpixels(): number;
			iterate(opts?: {num_iterations?: number}): null;
			getLabels(labels_out: Mat): null;
			getLabelContourMask(image: Mat, opts?: {thick_line?: boolean}): null;
			enforceLabelConnectivity(opts?: {min_element_size?: number}): null;
		}
		
		class SuperpixelSEEDS{
			getNumberOfSuperpixels(): number;
			iterate(img: Mat, opts?: {num_iterations?: number}): null;
			getLabels(labels_out: Mat): null;
			getLabelContourMask(image: Mat, opts?: {thick_line?: boolean}): null;
		}
		
		class SuperpixelSLIC{
			getNumberOfSuperpixels(): number;
			iterate(opts?: {num_iterations?: number}): null;
			getLabels(labels_out: Mat): null;
			getLabelContourMask(image: Mat, opts?: {thick_line?: boolean}): null;
			enforceLabelConnectivity(opts?: {min_element_size?: number}): null;
		}
				}
		namespace segmentation {

			class GraphSegmentation{
				processImage(src: Mat, dst: Mat): null;
				setSigma(sigma: number): null;
				getSigma(): number;
				setK(k: number): null;
				getK(): number;
				setMinSize(min_size: number): null;
				getMinSize(): number;
			}
			
			class SelectiveSearchSegmentation{
				setBaseImage(img: Mat): null;
				switchToSingleStrategy(opts?: {k?: number, sigma?: number}): null;
				switchToSelectiveSearchFast(opts?: {base_k?: number, inc_k?: number, sigma?: number}): null;
				switchToSelectiveSearchQuality(opts?: {base_k?: number, inc_k?: number, sigma?: number}): null;
				addImage(img: Mat): null;
				clearImages(): null;
				addGraphSegmentation(g: GraphSegmentation): null;
				clearGraphSegmentations(): null;
				addStrategy(s: SelectiveSearchSegmentationStrategy): null;
				clearStrategies(): null;
				process(rects: Rect[]): null;
			}
			
			class SelectiveSearchSegmentationStrategy{
				setImage(img: Mat, regions: Mat, sizes: Mat, opts?: {image_id?: number}): null;
				get(r1: number, r2: number): number;
				merge(r1: number, r2: number): null;
			}
			
			class SelectiveSearchSegmentationStrategyColor{
			}
			
			class SelectiveSearchSegmentationStrategyFill{
			}
			
			class SelectiveSearchSegmentationStrategyMultiple{
				addStrategy(g: SelectiveSearchSegmentationStrategy, weight: number): null;
				clearStrategies(): null;
			}
			
			class SelectiveSearchSegmentationStrategySize{
			}
			
			class SelectiveSearchSegmentationStrategyTexture{
			}
					}
	}
}
