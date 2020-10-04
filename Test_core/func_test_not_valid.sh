#!/bin/sh

FLAGS=""

rm -rf 1.txt
rm -rf 2.txt
CHAMP="42.cor"
./corewar $FLAGS ./champs_for_etalon/$CHAMP > 1.txt
./vm $FLAGS ./champs_for_our_project/$CHAMP > 2.txt
echo Diff 1 1 42.cor -----------------------------------------
diff -u 1.txt 2.txt
echo Diff 1 1 end --------------------------------------------


rm -rf 1.txt
rm -rf 2.txt
CHAMP="bee_gees.cor" 
./corewar $FLAGS ./champs_for_etalon/$CHAMP > 1.txt
./vm $FLAGS ./champs_for_our_project/$CHAMP > 2.txt
echo Diff 1 2 bee_gees.cor ============================================
diff -u 1.txt 2.txt 
echo Diff 1 2 end ============================================


rm -rf 1.txt
rm -rf 2.txt
CHAMP="mortel.cor"
./corewar $FLAGS ./champs_for_etalon/$CHAMP > 1.txt
./vm $FLAGS ./champs_for_our_project/$CHAMP > 2.txt
echo Diff 1 3 kamelkaze.cor ============================================
diff -u 1.txt 2.txt
echo Diff 1 3 end ============================================


rm -rf 1.txt
rm -rf 2.txt
CHAMP="jumper.cor"
./corewar $FLAGS ./champs_for_etalon/$CHAMP > 1.txt
./vm $FLAGS ./champs_for_our_project/$CHAMP > 2.txt
echo Diff 1 4 bee_gees.cor ============================================
diff -u 1.txt 2.txt
echo Diff 1 4 end ============================================


rm -rf 1.txt
rm -rf 2.txt
CHAMP1="mortel.cor"
CHAMP2="toto.cor"
./corewar $FLAGS ./champs_for_etalon/$CHAMP1 ./champs_for_etalon/$CHAMP2  > 1.txt
./vm $FLAGS ./champs_for_our_project/$CHAMP1 ./champs_for_our_project/$CHAMP2 > 2.txt
echo Diff 2 1 ============================================
diff -u 1.txt 2.txt
echo Diff 2 1 end ============================================


rm -rf 1.txt
rm -rf 2.txt
CHAMP1="bee_gees.cor"
CHAMP2="barriere.cor"
./corewar $FLAGS ./champs_for_etalon/$CHAMP1 ./champs_for_etalon/$CHAMP2  > 1.txt
./vm $FLAGS ./champs_for_our_project/$CHAMP1 ./champs_for_our_project/$CHAMP2 > 2.txt
echo Diff 2 2 ============================================
diff -u 1.txt 2.txt
echo Diff 2 2 end ============================================


rm -rf 1.txt
rm -rf 2.txt
CHAMP1="bigzork.cor"
CHMAP2="sebc.cor"
CHAMP3="jumper.cor"
./corewar $FLAGS ./champs_for_etalon/$CHAMP1 ./champs_for_etalon/$CHAMP2 ./champs_for_etalon/$CHAMP3 > 1.txt
./vm $FLAGS ./champs_for_our_project/$CHAMP1 ./champs_for_our_project/$CHAMP2 ./champs_for_our_project/$CHAMP3 > 2.txt
echo Diff 3 1 ============================================
diff -u 1.txt 2.txt
echo Diff 3 1 end ============================================


rm -rf 1.txt
rm -rf 2.txt
CHAMP1="bee_gees.cor"
CHAMP2="new.cor"
CHAMP3="toto.cor"
./corewar $FLAGS ./champs_for_etalon/$CHAMP1 ./champs_for_etalon/$CHAMP2 ./champs_for_etalon/$CHAMP3 > 1.txt
./vm $FLAGS ./champs_for_our_project/$CHAMP1 ./champs_for_our_project/$CHAMP2 ./champs_for_our_project/$CHAMP3 > 2.txt
echo Diff 3 2 ============================================
diff -u 1.txt 2.txt
echo Diff 3 2 end ============================================
