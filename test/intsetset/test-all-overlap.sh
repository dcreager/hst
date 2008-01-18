#!/bin/bash

cd `dirname "$0"`

for c in `cat intsetset-tests`; do
    echo -n "$c... "
    if ./test-overlap < $c.overlap-input; then
        echo PASS
    else
        echo FAIL
        exit 1
    fi
done