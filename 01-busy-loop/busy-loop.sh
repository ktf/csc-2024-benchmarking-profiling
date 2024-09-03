for x in busy-loop busy-loop-return-value-dep busy-loop-iteration-dep busy-loop-iteration-dep-correct; do
  cat $x.cc
  c++ -O2 $x.cc -o $x
  time ./$x || true
  objdump -d $x
done
