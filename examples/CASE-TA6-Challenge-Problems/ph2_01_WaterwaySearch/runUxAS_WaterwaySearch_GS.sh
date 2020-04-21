#! /bin/sh

SCRIPT=$(readlink -f "$0")
SCRIPT_DIR=$(dirname "$SCRIPT")
RUN_DIR="${SCRIPT_DIR}/RUNDIR_WaterwaySearch_GS"

BIN="${SCRIPT_DIR}/../../../build/uxas"

rm -rf ${RUN_DIR}
mkdir -p ${RUN_DIR}
cd ${RUN_DIR}
$BIN -cfgPath ${SCRIPT_DIR}/cfg_WaterwaySearch_GS.xml

