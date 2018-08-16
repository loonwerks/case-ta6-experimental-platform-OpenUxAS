#! /bin/bash

SAVE_DIR=$(pwd)

SUFFIX="-Vehicle400"

RM_DATAWORK="rm -R ./datawork${SUFFIX}"
RM_LOG="rm -R ./log${SUFFIX}"

BIN="../../../../../build/uxas"

mkdir -p RUNDIR_WaterwaySearch${SUFFIX}
cd RUNDIR_WaterwaySearch${SUFFIX}
$RM_DATAWORK
$RM_LOG
$BIN -cfgPath ../cfg_WaterwaySearch${SUFFIX}.xml

