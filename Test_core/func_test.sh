#!/bin/sh

FLAGS="-d 1500"

rm -rf 1.txt
rm -rf 2.txt
./corewar $FLAGS ./valid_champs_etalon/katchup.cor > 1.txt
./vm $FLAGS ./valid_champs_our/katchup.cor > 2.txt
echo "------------------------------------------------------------------------------"
echo Diff 1 1 katchup.cor
diff -u 1.txt 2.txt
echo Diff 1 1 end
echo "------------------------------------------------------------------------------"


rm -rf 1.txt
rm -rf 2.txt
./corewar $FLAGS ./valid_champs_etalon/tchupka.cor > 1.txt
./vm $FLAGS ./valid_champs_our/tchupka.cor > 2.txt
echo "------------------------------------------------------------------------------"
echo Diff 1 2 tchupka.cor
diff -u 1.txt 2.txt
echo Diff 1 2 end
echo "------------------------------------------------------------------------------"

rm -rf 3.txt
rm -rf 4.txt
./corewar $FLAGS ./valid_champs_etalon/kamelkaze.cor > 3.txt
./vm $FLAGS ./valid_champs_our/kamelkaze.cor > 4.txt
echo "------------------------------------------------------------------------------"
echo Diff 1 3 kamelkaze.cor
diff -u 1.txt 2.txt
echo Diff 1 3 end
echo "------------------------------------------------------------------------------"

FLAGS="-d 25000"
rm -rf 1.txt
rm -rf 2.txt
./corewar $FLAGS ./valid_champs_etalon/katchup.cor ./valid_champs_etalon/bee_gees.cor  > 1.txt
./vm $FLAGS ./valid_champs_our/katchup.cor ./valid_champs_our/bee_gees.cor > 2.txt 
echo "------------------------------------------------------------------------------"
echo Diff 2 1
diff -u 1.txt 2.txt
echo Diff 2 1 end
echo "------------------------------------------------------------------------------"

rm -rf 1.txt
rm -rf 2.txt
./corewar $FLAGS ./valid_champs_etalon/katchup.cor ./valid_champs_etalon/tchupka.cor  > 1.txt
./vm $FLAGS ./valid_champs_our/katchup.cor ./valid_champs_our/tchupka.cor > 2.txt
echo "------------------------------------------------------------------------------"
echo Diff 2 2
diff -u 1.txt 2.txt
echo Diff 2 2 end
echo "------------------------------------------------------------------------------"

rm -rf 1.txt
rm -rf 2.txt
./corewar $FLAGS ./valid_champs_etalon/kamelkaze.cor ./valid_champs_etalon/bee_gees.cor ./valid_champs_etalon/tchupka.cor > 1.txt
./vm $FLAGS ./valid_champs_our/kamelkaze.cor ./valid_champs_our/bee_gees.cor ./valid_champs_our/tchupka.cor > 2.txt
echo "------------------------------------------------------------------------------"
echo Diff 3 1
diff -u 1.txt 2.txt
echo Diff 3 1 end
echo "------------------------------------------------------------------------------"


rm -rf 1.txt
rm -rf 2.txt
./corewar $FLAGS ./valid_champs_etalon/katchup.cor ./valid_champs_etalon/tchupka.cor ./valid_champs_etalon/bee_gees.cor > 1.txt
./vm $FLAGS ./valid_champs_our/katchup.cor ./valid_champs_our/tchupka.cor ./valid_champs_our/bee_gees.cor > 2.txt
echo "------------------------------------------------------------------------------"
echo Diff 3 2
diff -u 1.txt 2.txt
echo Diff 3 2 end
echo "------------------------------------------------------------------------------"

rm -rf 1.txt
rm -rf 2.txt
rm -rf 3.txt
rm -rf 4.txt