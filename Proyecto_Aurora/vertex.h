#ifndef VERTEX_H
#define VERTEX_H


class vertex
{
public:
    vertex();
    int getWeight() const;
    void setWeight(int value);

    int getSourceNode() const;
    void setSourceNode(int value);

    int getTargetNode() const;
    void setTargetNode(int value);

private:
    int Weight;
    int SourceNode;
    int TargetNode;
};

#endif // VERTEX_H
