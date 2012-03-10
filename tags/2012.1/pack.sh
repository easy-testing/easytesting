zip -r zips/$1.zip exercicios/$1 exercicios/gtest/
svn add zips/$1.zip
zip -r zips/gabarito_$1.zip gabaritos/$1 gabaritos/gtest/
svn add zips/gabarito_$1.zip
