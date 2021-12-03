cat /etc/passwd | sed '/^#/d' | awk 'NR % 2 == 0' | cut -f 1 -d : | rev | sort -r | awk "NR >= $FT_LINE1 && NR <= $FT_LINE2" | tr "\n" "," | sed "s/,/, /g" | rev | sed "s/ ,/\./" | rev |  tr -d '\n'

