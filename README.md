% HST

HST is a library and set of command-line programs for processing CSP
scripts.  The goal for the 1.0 release is to support refinement
checking in the traces (T), stable failures (F), and
failures-divergences (N) semantic models, all of which are described
in [[1]](#bib1).

[1] <a name="bib1"/>
:   A. W. Roscoe.  /The theory and practice of concurrency/.  Prentice
    Hall, 1998.  ISBN 0-13-6774409-5.
    <http://web.comlab.ox.ac.uk/oucl/publications/books/concurrency/>

HST is divided into two major sections: the CSP₀ library, written in
C++, and the CSPM libary, written in Haskell.  C++ was chosen for
speed, since all LTS generation and refinement checking happens in the
CSP₀ library.  Haskell was chosen since CSPM is a lazy, functional
lanaguage — this us allows to use the same features of Haskell and not
have to implement a lazy functional interpreter ourselves.

For installation instructions, please see the INSTALL file.  There are
currently two command-line programs — “cspm” and “csp0”.  The first
allows you evaluate expressions in a CSPM script, and to compile CSPM
process expressions into the corresponding CSP₀.  The second allows
you to perform refinement checks on these compiled CSP₀ scripts.  Each
program is self-documented; run “csp0 help” or “cspm help” for usage
details.  The CSP₀ language is described in the csp0.html file, which
should be installed as part of the standard installation process.  The
most recent (and complete) description of the CSPM language can be
found in the FDR2 reference manual [[2]](#bib2).

[2] <a name="bib2"/>
:   Formal Systems (Europe) Ltd.  /Failures-Divergence Refinement:
    FDR2 Manual/.  2005.
    <http://www.fsel.com/>
