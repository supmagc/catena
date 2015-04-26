struct PSIN {
    float4 vColor: COLOR;
};

float4 main(PSIN oIn) : COLOR
{
    return oIn.vColor; // float4(1.0f, 1.0f, 1.0f, 1.0f);
}