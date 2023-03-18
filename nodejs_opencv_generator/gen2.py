#!/usr/bin/env python

from __future__ import print_function
import hdr_parser, sys, re, os
from pprint import pprint
from classes.python_wrapper_generator import PythonWrapperGenerator


if __name__ == "__main__":
    srcfiles = hdr_parser.opencv_hdr_list
    dstdir = "/Users/vp/tmp"
    if len(sys.argv) > 1:
        dstdir = sys.argv[1]
    if len(sys.argv) > 2:
        with open(sys.argv[2], 'r') as f:
            srcfiles = [l.strip() for l in f.readlines()]
    generator = PythonWrapperGenerator()
    generator.gen(srcfiles, dstdir)
