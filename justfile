#!/usr/bin/env just --justfile

default:
    @just --choose

bootstrap:
    #!/usr/bin/env bash
    set -euxo pipefail
    python3 -m venv .venv/
    source .venv/bin/activate
    pip install west
    west init -l config/
    west update
    west zephyr-export
    pip install -r zephyr/scripts/requirements-base.txt

update:
    .venv/bin/west update

build:
	.venv/bin/west build \
	    --pristine \
	    --build-dir=build/nice60 \
	    --board=nice60 \
	    zmk/app \
	    -- \
	    -DZMK_CONFIG="{{justfile_directory()}}/config/"

clean:
	rm -rf build/
