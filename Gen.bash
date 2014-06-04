#!/bin/bash/
pdflatex Book.tex
bibtex Book.aux
pdflatex Book.tex
#okular Book.pdf
