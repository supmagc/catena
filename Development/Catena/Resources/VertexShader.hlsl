struct VSOUT {
    float4 vPos: POSITION;
    float4 vColor: COLOR0;
};

VSOUT main(float4 vPos: POSITION, float4 vColor: COLOR)
{
    VSOUT oOut;
    oOut.vPos = vPos;
    oOut.vColor = vColor;
    return oOut;
}