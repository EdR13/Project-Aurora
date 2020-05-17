#ifndef EDGE_H
#define EDGE_H


class edge
{
public:
    edge();
    int getWeight() const;
    void setWeight(int value);

    int getSourceNode() const;
    void setSourceNode(int value);

    int getTargetNode() const;
    void setTargetNode(int value);

    bool getBidirectional() const;
    void setBidirectional(bool value);

private:
    int Weight;
    int SourceNode;
    int TargetNode;
    bool bidirectional = false;
};

#endif // EDGE_H
