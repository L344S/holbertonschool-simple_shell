#!/usr/bin/env bash

set -e

# Obtain the directory of the script
SCRIPTDIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
# Obtain the root directory of the project
ROOTDIR="$(cd "${SCRIPTDIR}/.." && pwd)"

set -x

# Generate AUTHORS file content
cat > "${ROOTDIR}/AUTHORS" <<- EOF
	# File @generated by hack/generate-authors.sh. DO NOT EDIT.
	# This file lists all contributors to the repository.
	# See hack/generate-authors.sh to make modifications.

	$(git -C "$ROOTDIR" log --format='%aN <%aE>' | LC_ALL=C.UTF-8 sort -uf)
EOF