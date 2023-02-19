{
  inputs.flake-utils.url = "github:numtide/flake-utils";

  outputs = { self, nixos, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let pkgs = nixos.legacyPackages.${system};
      in {
        devShells.default = pkgs.mkShell {
          packages = with pkgs; [
            yarn
            tree-sitter
          ];
        };
      });
}
