# This is a template for all makefiles.

#Set the list of files to be deleted by clean (Targets can also be specified).:
CLEAN_TARGETS += $(ALL_LIBRARIES) *.log *.clog

# Set the list of target to make while testing.  By default, mytest is the
# only target added.  If the name of the target is changed in the rules then
# the name should be changed accordingly in this list.

TEST_TARGETS += foreign warning

ifeq ($(strip $(ROOTTEST_HOME)),)
	export ROOTTEST_HOME=$(shell expr $(PWD) : '\(.*/roottest/\)')
endif

include $(ROOTTEST_HOME)/scripts/Rules.mk


# Outputs a message if the FAIL variable is null

testWithFailure:
ifeq ($(FAIL),)
	$(WarnFailTest)
endif

testWithDiff: testWithDiff.log testWithDiff.ref
	$(TestDiff)

data1_C.$(DllSuf) : data.h data1.C

data2_C.$(DllSuf) : data.h data2.C

data1.root: writefile.C data1_C.$(DllSuf)
	$(CMDECHO) root.exe -b -q -l 'writefile.C(1)' 2>&1 > data1.log

data2.root: writefile.C data2_C.$(DllSuf)
	$(CMDECHO) root.exe -b -q -l 'writefile.C(2)' 2>&1 > data2.log

data3.root: writefile.C data3_C.$(DllSuf)
	$(CMDECHO) root.exe -b -q -l 'writefile.C(3)' 2>&1 > data3.log

data4.root: writefile.C data4_C.$(DllSuf)
	$(CMDECHO) root.exe -b -q -l 'writefile.C(4)' 2>&1 > data4.log

data5.root: writefile.C data5_C.$(DllSuf)
	$(CMDECHO) root.exe -b -q -l 'writefile.C(5)' 2>&1 > data4.log

data6.root: writefile.C data6_C.$(DllSuf)
	$(CMDECHO) root.exe -b -q -l 'writefile.C(6)' 2>&1 > data4.log

foreign.log: data1.root data2.root data3.root data4.root data2_C.$(DllSuf)

warning.log: data1.root data2.root data3.root data4.root data5.root \
	         data6.root data2_C.$(DllSuf) checkWarn.C
	$(CMDECHO) (root.exe -q -b -l 'checkWarn.C(0)' \
	    && root.exe -q -b -l 'checkWarn.C(1)' \
	    && root.exe -q -b -l 'checkWarn.C(2)' \
	    && root.exe -q -b -l 'checkWarn.C(3)' \
	    && root.exe -q -b -l 'checkWarn.C(4)' \
	    && root.exe -q -b -l 'checkWarn.C(10)' \
	    && root.exe -q -b -l 'checkWarn.C(11)' \
	    && root.exe -q -b -l 'checkWarn.C(12)' \
	    && root.exe -q -b -l 'checkWarn.C(13)' \
	    && root.exe -q -b -l 'checkWarn.C(14)' \
	    && root.exe -q -b -l 'checkWarn.C(15)' \
	    && root.exe -q -b -l 'checkWarn.C(16)' \
	    && root.exe -q -b -l 'checkWarn.C(17)' \
	    && root.exe -q -b -l 'checkWarn.C(18)' \
	    ) 2>&1 | sed -e 's@offset=  [0-9]*@offset= n/a@' > warning.log

foreign: foreign.log
	$(TestDiff)

warning: warning.log
	$(TestDiff)