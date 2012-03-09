cd 2012.1
svn mv gabarito_$1/ gabaritos/$1
cd ..
zip -r 2012.1/zips/$1.zip 2012.1/$1 2012.1/gtest/
zip -r 2012.1/zips/gabarito_$1.zip 2012.1/gabaritos/$1 2012.1/gabaritos/gtest/
svn add 2012.1/zips/$1.zip
svn add 2012.1/zips/gabarito_$1.zip
svn ci -m "Zip de $1"
