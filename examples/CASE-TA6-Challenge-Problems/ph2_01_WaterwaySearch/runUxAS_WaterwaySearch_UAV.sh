#! /bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
RUN_DIR="$(pwd)/RUNDIR_WaterwaySearch_UAV"

BIN="${SCRIPT_DIR}/../../../build/uxas"

rm -rf ${RUN_DIR}
mkdir -p ${RUN_DIR}
cd ${RUN_DIR}
$BIN -cfgPath ${SCRIPT_DIR}/cfg_WaterwaySearch_UAV.xml

