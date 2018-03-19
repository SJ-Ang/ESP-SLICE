#formchk test.chk

#cubegen 12 Density=SCF test.fchk pyrene_den.cube 100 h
#cubegen 12 Potential=SCF test.fchk pyrene_esp.cube 100 h esp2.cube

sed "7,$ d" pyrene_esp.cube > esp.out
sed "1,3 d" esp.out | cut -c "1-5" > dim.txt
a=$(sed -n 3p esp.out | cut -c "1-5"|bc) 
echo $a > mol.xyz
b=$(echo $a+6|bc)
sed -n '3,6 p' pyrene_esp.cube | cut -c "6-42" > specs.txt 
sed -n '7,'$b' p' pyrene_esp.cube >> mol.xyz 
sed '1,'$b' d' pyrene_esp.cube > esp.txt
gcc slice.c -o slice.out
./slice.out > pyrene_slice.dat
rm *txt *out *xyz


