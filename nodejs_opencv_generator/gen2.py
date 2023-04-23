#!/usr/bin/env python

from __future__ import print_function
import hdr_parser, sys
# from .classes.nodejs_wrapper_generator import NodejsWrapperGenerator
from nodejs_opencv_generator.classes.nodejs_wrapper_generator import NodejsWrapperGenerator

if __name__ == "__main__":
    
    """
    Generate Node.js bindings for OpenCV
    First argument is the output directory
    Second argument is a file with a list of header files to process
    """
    srcfiles = hdr_parser.opencv_hdr_list
    dstdir = "/Users/vp/tmp"
    if len(sys.argv) > 1:
        dstdir = sys.argv[1]
    if len(sys.argv) > 2:
        with open(sys.argv[2], 'r') as f:
            srcfiles = [l.strip() for l in f.readlines()]
    generator = NodejsWrapperGenerator()
    generator.gen(srcfiles, dstdir)
