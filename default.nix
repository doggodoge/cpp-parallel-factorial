{ sources ? import ./nix/sources.nix
, pkgs ? import sources.nixpkgs {}
}:

pkgs.stdenv.mkDerivation {
  name = "factorial";
  version = "0.0.1";
  src = ./.;

  nativeBuildInputs = [
    pkgs.llvmPackages_latest.clang
    pkgs.ninja
    pkgs.cmake
  ];

  buildInputs = [
    pkgs.gmp
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

