struct VSOUT {
    float4 vPos: POSITION;
    float4 vCol : COLOR;
};

row_major float4x4 mWVP : register(c0);

VSOUT main(float4 vPos: POSITION, float4 vCol: COLOR)
{
    VSOUT oOut;
    oOut.vPos = mul(vPos, mWVP);
    oOut.vCol = vCol;
    return oOut;
}