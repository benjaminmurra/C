#!/bin/bash

imsOut=$(diff i_must_scream.out_example i_must_scream.out | wc -c)
imsEdit=$(diff i_must_scream.edit_example i_must_scream.out.edit | wc -c)

shdOut=$(diff shadow_over_innsmouth.out_example shadow_over_innsmouth.out | wc -c)
shdEdit=$(diff shadow_over_innsmouth.edit_example shadow_over_innsmouth.out.edit | wc -c)

if [ $imsOut -gt 0 ]; then
	printf "i_must_scream.out does not match the expected file. This should be an exact copy of i_must_scream and i_must_scream.out_example.."
	exit -1
fi

if [ $imsEdit -gt 0 ]; then
	printf "i_must_scream.out.edit does not match the expected file. This should be an exact copy of i_must_scream.edit_example."
	exit -2
fi

if [ $shdOut -gt 0 ]; then
	printf "shadow_over_innsmouth.out does not match the expected file. This should be an exact copy of shadow_over_innsmouth and shadow_over_innsmouth.out_example."
	exit -3
fi

if [ $shdEdit -gt 0 ]; then
	printf "shadow_over_innsmouth.out.edit does not match the expected file. This should be an exact copy of shadow_over_innsmouth.edit_example"
	exit -4
fi
