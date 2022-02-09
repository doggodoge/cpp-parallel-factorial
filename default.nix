with import <nixpkgs> {};

stdenv.mkDerivation {
  name = "factorial";
  version = "0.0.1";
  src = ./.;

  nativeBuildInputs = [
    clang
    ninja
    cmake
  ];

  buildInputs = [
    gmp
  ];

  configurePhase = ''
    mkdir nix-build
    cd nix-build
    cmake .. -G Ninja
  '';

  buildPhase = ''
    ninja
  '';

  installPhase = ''
    mkdir -p $out/bin
    cp factorial $out/bin
  '';
}

