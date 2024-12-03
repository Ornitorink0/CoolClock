# ! THIS FILE IS AUTO-GENERATED !
pkgname=coolclock
pkgver=1.0
pkgdesc="A Way to Flex the Clock on Linux"
pkgrel=1
arch=(i686 x86_64)
depends=(gcc make)
license=(MIT)
url="https://"
pkgauthor="Ornitorink0"

# Build the package using make
build() {
  cd "$srcdir"
  make
}

# This function packages the built software into the desired directory structure.
#
# It changes the current directory to the source directory and then runs
# the `make install` command with the `DESTDIR` variable set to the package
# directory. This ensures that the software is installed into the package
# directory, preparing it for distribution.
package() {
  cd "$srcdir"
  make DESTDIR="$pkgdir" install
}
