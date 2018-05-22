with import <nixpkgs> {};

stdenv.mkDerivation rec {
  name = "subnetgen";
  src = stdenv.lib.cleanSource ./.;

  enableParallelBuilding = true;
  nativeBuildInputs = [ autoreconfHook ];
}
