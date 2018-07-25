with import <nixpkgs> {};

stdenv.mkDerivation rec {
  name = "subnetgen";
  src = lib.cleanSource ./.;

  nativeBuildInputs = [ meson ninja ];
}
