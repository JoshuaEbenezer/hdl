# ----------------------------------------------------------------------------
#       _____
#      *     *
#     *____   *____
#    * *===*   *==*
#   *___*===*___**  AVNET
#        *======*
#         *====*
# ----------------------------------------------------------------------------
# 
#  This design is the property of Avnet.  Publication of this
#  design is not authorized without written consent from Avnet.
# 
#  Please direct any questions to the MiniZed community support forum:
#     http://www.minized.org/forum
# 
#  Product information is available at:
#     http://www.minized.org/product/minized
# 
#  Disclaimer:
#     Avnet, Inc. makes no warranty for the use of this code or design.
#     This code is provided  "As Is". Avnet, Inc assumes no responsibility for
#     any errors, which may appear in this code, nor does it make a commitment
#     to update the information contained herein. Avnet, Inc specifically
#     disclaims any implied warranties of fitness for a particular purpose.
#                      Copyright(c) 2017 Avnet, Inc.
#                              All rights reserved.
# 
# ----------------------------------------------------------------------------
# 
#  Create Date:         Aug 14, 2017
#  Design Name:         MiniZed SpeedWay HW Platform
#  Module Name:         make_minized_speedway.tcl
#  Project Name:        MiniZed SpeedWay Training
#  Target Devices:      Xilinx Zynq-7000
#  Hardware Boards:     MiniZed SOM
# 
#  Tool versions:       Xilinx Vivado 2017.1
# 
#  Description:         Build Script for MiniZed SpeedWay HW Platform
# 
#  Dependencies:        make.tcl
#
#  Revision:            Aug 14, 2017: 1.00 Initial version
# 
# ----------------------------------------------------------------------------

# Build SpeedWay HW Platform for MiniZed 
set argv [list board=MINIZED project=minized_speedway sdk=yes close_project=yes version_override=yes]
set argc [llength $argv]
source ./make.tcl -notrace
