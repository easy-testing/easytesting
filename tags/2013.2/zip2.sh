~/clean.sh
zip -r $1.zip $1 $2 -x ".*"
zip -r gabarito_$1.zip gabaritos/$1 gabaritos/$2 -x ".*"
