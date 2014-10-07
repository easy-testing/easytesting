~/clean.sh
zip -r zip/$1.zip $1 $2 -x ".*"
zip -r zip/gabarito_$1.zip gabaritos/$1 gabaritos/$2 -x ".*"
svn add zip/$1.zip
svn add zip/gabarito_$1.zip
