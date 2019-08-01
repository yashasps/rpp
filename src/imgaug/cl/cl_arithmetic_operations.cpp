#include <cl/rpp_cl_common.hpp>
#include "cl_declarations.hpp"

/********* Absolute Difference *********/

RppStatus
absolute_difference_cl ( cl_mem srcPtr1,cl_mem srcPtr2,
                 RppiSize srcSize, cl_mem dstPtr,
                 RppiChnFormat chnFormat, unsigned int channel,
                 cl_command_queue theQueue)
{
    unsigned short counter=0;
    cl_kernel theKernel;
    cl_program theProgram;
    CreateProgramFromBinary(theQueue,"absolute_difference.cl","absolute_difference.cl.bin","absolute_difference",theProgram,theKernel);
    // cl_kernel_initializer(theQueue,
    //                       "absolute_difference.cl",
    //                       "absolute_difference",
    //                       theProgram, theKernel);

    //---- Args Setter
    clRetainKernel(theKernel);
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &srcPtr1);
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &srcPtr2);
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &dstPtr);
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &srcSize.height);
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &srcSize.width);
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &channel);
    //----

    size_t gDim3[3];
    gDim3[0] = srcSize.width;
    gDim3[1] = srcSize.height;
    gDim3[2] = channel;
    cl_kernel_implementer (theQueue, gDim3, NULL/*Local*/, theProgram, theKernel);

    return RPP_SUCCESS;

}

 /************* Arithmetic Add ************/

RppStatus
add_cl ( cl_mem srcPtr1,cl_mem srcPtr2,
                 RppiSize srcSize, cl_mem dstPtr,
                 RppiChnFormat chnFormat, unsigned int channel,
                 cl_command_queue theQueue)
{
    unsigned short counter=0;
    cl_int err;
    cl_kernel theKernel;
    cl_program theProgram;
    // clGetCommandQueueInfo(  theQueue,
    //                         CL_QUEUE_DEVICE, sizeof(cl_device_id), &theDevice, NULL);
    err = CreateProgramFromBinary(theQueue,"add.cl","add.cl.bin","add",theProgram,theKernel);
    // cl_kernel_initializer(theQueue,
    //                       "add.cl",
    //                       "add",
    //                       theProgram, theKernel);

    //---- Args Setter
    err = clRetainKernel(theKernel);
    err = clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &srcPtr1);
    err |= clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &srcPtr2);
    err |= clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &dstPtr);
    err |= clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &(srcSize.height));
    err |= clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &(srcSize.width));
    err |= clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &(channel));
    //----
    size_t gDim3[3];
    gDim3[0] = srcSize.width;
    gDim3[1] = srcSize.height;
    gDim3[2] = channel;
    cl_kernel_implementer (theQueue, gDim3, NULL/*Local*/, theProgram, theKernel);

    return RPP_SUCCESS;

}


/**************** Arithmetic Subtract *******************/
RppStatus
subtract_cl ( cl_mem srcPtr1,cl_mem srcPtr2,
                 RppiSize srcSize, cl_mem dstPtr,
                 RppiChnFormat chnFormat, unsigned int channel,
                 cl_command_queue theQueue)
{
    unsigned short counter=0;
    cl_kernel theKernel;
    cl_program theProgram;

    CreateProgramFromBinary(theQueue,"subtract.cl","subtract.cl.bin","subtract",theProgram,theKernel);
    clRetainKernel(theKernel); 

    // cl_kernel_initializer(theQueue,
    //                       "subtract.cl",
    //                       "subtract",
    //                       theProgram, theKernel);

    //---- Args Setter
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &srcPtr1);
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &srcPtr2);
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &dstPtr);
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &srcSize.height);
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &srcSize.width);
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &channel);
    //----

    size_t gDim3[3];
    gDim3[0] = srcSize.width;
    gDim3[1] = srcSize.height;
    gDim3[2] = channel;
    cl_kernel_implementer (theQueue, gDim3, NULL/*Local*/, theProgram, theKernel);

    return RPP_SUCCESS;

}

/**************** Accumulate *******************/
RppStatus
accumulate_cl ( cl_mem srcPtr1,cl_mem srcPtr2,
                 RppiSize srcSize,
                 RppiChnFormat chnFormat, unsigned int channel,
                 cl_command_queue theQueue)
{
    unsigned short counter=0;
    cl_kernel theKernel;
    cl_program theProgram;

    CreateProgramFromBinary(theQueue,"accumulate.cl","accumulate.cl.bin","accumulate",theProgram,theKernel);
    clRetainKernel(theKernel); 

    // cl_kernel_initializer(theQueue,
    //                       "accumulate.cl",
    //                       "accumulate",
    //                       theProgram, theKernel);

    //---- Args Setter
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &srcPtr1);
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &srcPtr2);
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &srcSize.height);
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &srcSize.width);
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &channel);
    //----

    size_t gDim3[3];
    gDim3[0] = srcSize.width;
    gDim3[1] = srcSize.height;
    gDim3[2] = channel;
    cl_kernel_implementer (theQueue, gDim3, NULL/*Local*/, theProgram, theKernel);

    return RPP_SUCCESS;

}

/**************** Accumulate weighted *******************/

RppStatus
accumulate_weighted_cl ( cl_mem srcPtr1,cl_mem srcPtr2,
                 RppiSize srcSize, Rpp64f alpha,
                 RppiChnFormat chnFormat, unsigned int channel,
                 cl_command_queue theQueue)
{
    unsigned short counter=0;
    cl_kernel theKernel;
    cl_program theProgram;

    CreateProgramFromBinary(theQueue,"accumulate.cl","accumulate.cl.bin","accumulate_weighted",theProgram,theKernel);
    clRetainKernel(theKernel); 

    // cl_kernel_initializer(theQueue,
    //                       "accumulate.cl",
    //                       "accumulate_weighted",
    //                       theProgram, theKernel);

    //---- Args Setter
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &srcPtr1);
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &srcPtr2);
    clSetKernelArg(theKernel, counter++, sizeof(Rpp64f), &alpha);
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &srcSize.height);
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &srcSize.width);
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &channel);
    //----

    size_t gDim3[3];
    gDim3[0] = srcSize.width;
    gDim3[1] = srcSize.height;
    gDim3[2] = channel;
    cl_kernel_implementer (theQueue, gDim3, NULL/*Local*/, theProgram, theKernel);

    return RPP_SUCCESS;

}

RppStatus
tensor_add_cl(Rpp32u tensorDimension, cl_mem tensorDimensionValues, cl_mem srcPtr1,cl_mem srcPtr2, cl_mem dstPtr, cl_command_queue theQueue)
{
    
    unsigned short counter=0;
    cl_kernel theKernel;
    cl_program theProgram;

    CreateProgramFromBinary(theQueue,"tensor.cl","tensor.cl.bin","tensor_add",theProgram,theKernel);
    clRetainKernel(theKernel); 

    //---- Args Setter
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &tensorDimension);
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &tensorDimensionValues);
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &srcPtr1);
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &srcPtr2);
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &dstPtr);
    //----
    
    unsigned int* tensorDimensionValuesCopy;
    size_t dest_bytes = tensorDimension * sizeof(Rpp32u);
    tensorDimensionValuesCopy = (unsigned int*)malloc(dest_bytes);
    clEnqueueReadBuffer(theQueue, tensorDimensionValues, CL_TRUE, 0, dest_bytes, tensorDimensionValuesCopy, 0, NULL, NULL );
    
    size_t gDim3[3];
    if(tensorDimension == 1)
    {
        gDim3[0] = tensorDimensionValuesCopy[0];
        gDim3[1] = 1;
        gDim3[2] = 1;
    }
    else if(tensorDimension == 2)
    {
        gDim3[0] = tensorDimensionValuesCopy[0];
        gDim3[1] = tensorDimensionValuesCopy[1];
        gDim3[2] = 1;
    }
    else
    {
        gDim3[0] = 1280; //tensorDimensionValuesCopy[0];
        gDim3[1] = 720; //tensorDimensionValuesCopy[1];
        int value = 1;
        for(int i = 2 ; i < tensorDimension ; i++)
            value *= tensorDimensionValuesCopy[i];
        gDim3[2] = 3; //value;
    }
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &gDim3[0]);
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &gDim3[1]);
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &gDim3[2]);
    std::cout<<"12345";
    cl_kernel_implementer (theQueue, gDim3, NULL/*Local*/, theProgram, theKernel);

    return RPP_SUCCESS;
}

RppStatus
tensor_subtract_cl(Rpp32u tensorDimension, cl_mem tensorDimensionValues, cl_mem srcPtr1,cl_mem srcPtr2, cl_mem dstPtr, cl_command_queue theQueue)
{
    unsigned short counter=0;
    cl_kernel theKernel;
    cl_program theProgram;

    CreateProgramFromBinary(theQueue,"tensor.cl","tensor.cl.bin","tensor_subtract",theProgram,theKernel);
    clRetainKernel(theKernel); 

    //---- Args Setter
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &tensorDimension);
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &tensorDimensionValues);
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &srcPtr1);
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &srcPtr2);
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &dstPtr);
    //----

    unsigned int* tensorDimensionValuesCopy;
    size_t dest_bytes = tensorDimension * sizeof(Rpp32u);
    tensorDimensionValuesCopy = (unsigned int*)malloc(dest_bytes);
    clEnqueueReadBuffer(theQueue, tensorDimensionValues, CL_TRUE, 0, dest_bytes, tensorDimensionValuesCopy, 0, NULL, NULL );
    
    size_t gDim3[3];
    if(tensorDimension == 1)
    {
        gDim3[0] = tensorDimensionValuesCopy[0];
        gDim3[1] = 1;
        gDim3[2] = 1;
    }
    else if(tensorDimension == 2)
    {
        gDim3[0] = tensorDimensionValuesCopy[0];
        gDim3[1] = tensorDimensionValuesCopy[1];
        gDim3[2] = 1;
    }
    else
    {
        gDim3[0] = tensorDimensionValuesCopy[0];
        gDim3[1] = tensorDimensionValuesCopy[1];
        int value = 1;
        for(int i = 2 ; i < tensorDimension ; i++)
            value *= tensorDimensionValuesCopy[i];
        gDim3[2] = value;
    }
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &gDim3[0]);
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &gDim3[1]);
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &gDim3[2]);
    
    cl_kernel_implementer (theQueue, gDim3, NULL/*Local*/, theProgram, theKernel);

    return RPP_SUCCESS;
}

RppStatus
tensor_multiply_cl(Rpp32u tensorDimension, cl_mem tensorDimensionValues, cl_mem srcPtr1,cl_mem srcPtr2, cl_mem dstPtr, cl_command_queue theQueue)
{
    unsigned short counter=0;
    cl_kernel theKernel;
    cl_program theProgram;

    CreateProgramFromBinary(theQueue,"tensor.cl","tensor.cl.bin","tensor_multiply",theProgram,theKernel);
    clRetainKernel(theKernel); 

    //---- Args Setter
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &tensorDimension);
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &tensorDimensionValues);
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &srcPtr1);
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &srcPtr2);
    clSetKernelArg(theKernel, counter++, sizeof(cl_mem), &dstPtr);
    //----

    unsigned int* tensorDimensionValuesCopy;
    size_t dest_bytes = tensorDimension * sizeof(Rpp32u);
    tensorDimensionValuesCopy = (unsigned int*)malloc(dest_bytes);
    clEnqueueReadBuffer(theQueue, tensorDimensionValues, CL_TRUE, 0, dest_bytes, tensorDimensionValuesCopy, 0, NULL, NULL );
    
    size_t gDim3[3];
    if(tensorDimension == 1)
    {
        gDim3[0] = tensorDimensionValuesCopy[0];
        gDim3[1] = 1;
        gDim3[2] = 1;
    }
    else if(tensorDimension == 2)
    {
        gDim3[0] = tensorDimensionValuesCopy[0];
        gDim3[1] = tensorDimensionValuesCopy[1];
        gDim3[2] = 1;
    }
    else
    {
        gDim3[0] = tensorDimensionValuesCopy[0];
        gDim3[1] = tensorDimensionValuesCopy[1];
        int value = 1;
        for(int i = 2 ; i < tensorDimension ; i++)
            value *= tensorDimensionValuesCopy[i];
        gDim3[2] = value;
        
    }
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &gDim3[0]);
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &gDim3[1]);
    clSetKernelArg(theKernel, counter++, sizeof(unsigned int), &gDim3[2]);
    
    cl_kernel_implementer (theQueue, gDim3, NULL/*Local*/, theProgram, theKernel);

    return RPP_SUCCESS;    
}