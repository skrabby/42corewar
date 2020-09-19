#!/bin/sh

rm hex1.txt
rm hex2.txt
hexdump -v valid_champs_etalon/bee_gees.cor > hex1.txt
hexdump -v valid_champs_our/bee_gees.cor > hex2.txt
echo "Diff bee_gees.cor"
echo "=================================================="
diff -u hex1.txt hex2.txt
echo "=================================================="

rm hex1.txt
rm hex2.txt
hexdump -v valid_champs_etalon/42.cor > hex1.txt
hexdump -v valid_champs_our/42.cor > hex2.txt
echo "Diff 42.cor"
echo "=================================================="
diff -u hex1.txt hex2.txt
echo "=================================================="

rm hex1.txt
rm hex2.txt
hexdump -v valid_champs_etalon/barriere.cor > hex1.txt
hexdump -v valid_champs_our/barriere.cor > hex2.txt
echo "Diff barriere.cor"
echo "=================================================="
diff -u hex1.txt hex2.txt
echo "=================================================="


rm hex1.txt
rm hex2.txt
hexdump -v valid_champs_etalon/kamelkaze.cor > hex1.txt
hexdump -v valid_champs_our/kamelkaze.cor > hex2.txt
echo "Diff kamelkaze.cor"
echo "=================================================="
diff -u hex1.txt hex2.txt
echo "=================================================="


rm hex1.txt
rm hex2.txt
hexdump -v valid_champs_etalon/katchup.cor > hex1.txt
hexdump -v valid_champs_our/katchup.cor > hex2.txt
echo "Diff katchup.cor"
echo "=================================================="
diff -u hex1.txt hex2.txt
echo "=================================================="


rm hex1.txt
rm hex2.txt
hexdump -v valid_champs_etalon/tchupka.cor > hex1.txt
hexdump -v valid_champs_our/tchupka.cor > hex2.txt
echo "Diff tchupka.cor"
echo "=================================================="
diff -u hex1.txt hex2.txt
echo "=================================================="